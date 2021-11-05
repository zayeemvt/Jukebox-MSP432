/*
 * Buzzer.c
 *
 *  Created on: Jan 2, 2020
 *      Author: Matthew Zhong
 */

#include <HAL/Buzzer.h>
#include <HAL/Timer.h>

/**
 * Constructor for a CompleteNote object. CompleteNotes are useful to write
 * songs for this board.
 */
CompleteNote CompleteNote_construct(Note note, int octave, uint32_t duration)
{
    // The CompleteNote to build
    CompleteNote completeNote;

    // Initialize proper member variables from arguments
    completeNote.note = note;
    completeNote.octave = octave;
    completeNote.duration = SWTimer_construct(duration);
    completeNote.noteProgress = NOTE_START;

    // Return the completed object
    return completeNote;
}

/**
 * Main constructor function for a Buzzer object. Just like the LEDs, the user
 * should be able to construct a buzzer, set the output of the buzzer to a user
 * specified note, or turn off (mute) the buzzer. The constructor should call
 * the proper Driverlib functions which configure TimerA to connect its output
 * with the buzzer. It should also pre-fill out a Timer_A_PWMConfig so that when
 * the user tries to change what note is played, only a few members of the
 * config need to be changed before reconfiguration of TimerA. Finally, the
 * constructor should populate the referenceNotes field with the frequencies of
 * each note and octave up to a predefined maximum.
 *
 * @return a properly constructed Buzzer object
 */
Buzzer Buzzer_construct()
{
    // The Buzzer object we must build in this constructor
    Buzzer buzzer;

    // Temporary index variable whose use is repeated in several loops
    int i;
    Note note;

    // Configure the target pins to be used as Buzzer
    GPIO_setAsPeripheralModuleFunctionOutputPin(GPIO_PORT_P2, GPIO_PIN7,
                                                GPIO_PRIMARY_MODULE_FUNCTION);

    // Configure the Driverlib struct to use the proper clocksource dividers.
    // Notice that the timerPeriod and dutyCycle have not been initialized -
    // these two will be initialized when you actually tell the object to
    // generate the proper frequency in a separate method call.
    buzzer.config.clockSource = TIMER_A_CLOCKSOURCE_SMCLK;
    buzzer.config.clockSourceDivider = 64;
    buzzer.config.compareRegister = TIMER_A_CAPTURECOMPARE_REGISTER_4;
    buzzer.config.compareOutputMode = TIMER_A_OUTPUTMODE_RESET_SET;

    // To create the table of reference notes, we begin with A4, which has a
    // frequency of 440Hz.
    buzzer.referenceNotes[NOTE_A][4] = 440.0;

    // To descend half-steps until we hit C4, we divide A4 by a half-step
    // factor of 2^(1/12) per step, or 1.05946309436.
    for (note = NOTE_A; note > NOTE_C; note--) {
        buzzer.referenceNotes[note - 1][4] = buzzer.referenceNotes[note][4] / HALF_STEP;
    }

    // To ascend half-steps until we hit B4, we multiply A4 by a half-step
    // factor of 2^(1/12) per step, or 1.05946309436.
    for (note = NOTE_A; note < NOTE_B; note++) {
        buzzer.referenceNotes[note + 1][4] = buzzer.referenceNotes[note][4] * HALF_STEP;
    }

    // To fill all other octaves above, multiply the frequency from lower
    // octave's notes by 2.0 per octave. For example, to get A5, you
    // multiply the frequency of A4 by 2.0 so 440 * 2.0 = 880 Hz
    for (i = 4; i <= NUM_OCTAVES; i++) {
        for (note = NOTE_C; note <= NOTE_B; note++) {
            buzzer.referenceNotes[note][i + 1] = buzzer.referenceNotes[note][i] * 2.0;
        }
    }

    // To fill all other octaves below, divide the frequency from higher
    // octave's notes by 2.0 per octave. For example, to get A3, you
    // divide the frequency of A4 by 2.0 so 440 / 2.0 = 220 Hz
    for (i = 4; i > 0; i--) {
        Note note;
        for (note = NOTE_C; note <= NOTE_B; note++) {
            buzzer.referenceNotes[note][i - 1] = buzzer.referenceNotes[note][i] / 2.0;
        }
    }

    // Return the constructed Buzzer module at the end of construction
    return buzzer;
}

/**
 * Start playing a note from a properly set-up buzzer. This function behaves in
 * a way analagous to turning on and off an LED. When you call this method, you
 * set the buzzer to continuously play a note. The note will play forever until
 * you turn off the buzzer, just like how an LED stays on forever until you turn
 * off the LED. Use timers to govern how long a buzzer should play a note.
 *
 * @param buzzer:   The buzzer object from which to play notes
 * @param note:     The note to play (defined from the Note enum)
 * @param octave:   The octave to play the note from. Any input greater than
 *                  NUM_OCTAVES or less than 1 will result in a segfault.
 */
void Buzzer_playRawNote(Buzzer* buzzer, Note note, int octave)
{
    // Special case: If the note is silent, simply turn off the buzzer.
    if (note == NOTE_SILENT) {
        Timer_A_stopTimer(TIMER_A0_BASE);
    }

    // Otherwise, reconfigure the PWM config struct and start PWM generation
    else {

        // Compute the load value based off of which note and octave is chosen
        double frequency = buzzer->referenceNotes[note][octave];
        uint16_t divider = buzzer->config.clockSourceDivider;
        uint16_t loadValue = SYSTEM_CLOCK / (frequency * divider);

        // Update the config with the new computations
        buzzer->config.timerPeriod = loadValue;
        buzzer->config.dutyCycle = loadValue * 0.01;

        // Restart the buzzer's PWM
        Timer_A_generatePWM(TIMER_A0_BASE, &buzzer->config);
    }
}

/**
 * Turn off the buzzer. After turning off the buzzer, you must reinitialize the
 * buzzer's config struct through [Buzzer_playNote()] in order for sound to play
 * through the buzzer.
 *
 * @param buzzer:   The buzzer to stop and reinitialize
 */
void Buzzer_muteSound(Buzzer* buzzer)
{
    // Reset PWM config variables. The logic behind this is that with a duty
    // cycle of 0 and a timer period of SYSTEM_CLOCK, the buzzer attempts to
    // buzz only one time per second, which should be inaudible.
    buzzer->config.dutyCycle = 0;
    buzzer->config.timerPeriod = SYSTEM_CLOCK;

    // Stop Timer A from buzzing the buzzer
    Timer_A_stopTimer(TIMER_A0_BASE);
}

/**
 * A non-blocking function which continuously plays a given CompleteNote until
 * the duration specified in the note has elapsed. This function should be
 * continuously polled to continue to play the note until the function returns
 * true. The state of the note is determined through an FSM stored directly
 * in the note.
 *
 * @param buzzer:           The buzzer from which to play the note
 * @param completeNote:     The note to play
 *
 * @return true if the note has finished playing, and false otherwise
 */
bool Buzzer_playCompleteNote(Buzzer* buzzer, CompleteNote* completeNote)
{
    // Main FSM for playing a note
    switch (completeNote->noteProgress)
    {
        // If the note has yet to start, we start raw note playing
        case NOTE_START:
            Buzzer_playRawNote(buzzer, completeNote->note, completeNote->octave);
            SWTimer_start(&completeNote->duration);
            completeNote->noteProgress = NOTE_PLAYING;
            break;

        // When the note is in the middle of playing, we transition if the note
        // timer has finished
        case NOTE_PLAYING:
            if (SWTimer_expired(&completeNote->duration)) {
                Buzzer_muteSound(buzzer);
                completeNote->noteProgress = NOTE_FINISHED;
            }
            break;

        // The note is already finished so no state changes are needed here
        case NOTE_FINISHED:
            break;
    }

    // The function returns true when the note finishes and only then.
    return completeNote->noteProgress == NOTE_FINISHED;
}
