/*
 * PWM.h
 *
 *  Created on: Jan 2, 2020
 *      Author: Matthew Zhong
 */

#ifndef HAL_BUZZER_H_
#define HAL_BUZZER_H_

#include <HAL/Timer.h>
#include <ti/devices/msp432p4xx/driverlib/driverlib.h>

#define NUM_NOTES       12
#define NUM_OCTAVES     8
#define OCTAVE_LOW      2

/**
 * Predefined enums for each note. Do not change the order of the enumerated
 * variables, since we rely on its order to index the array of reference notes
 * correctly.
 */
enum _Note
{
    NOTE_C, NOTE_C_SHARP,
    NOTE_D, NOTE_D_SHARP,
    NOTE_E,
    NOTE_F, NOTE_F_SHARP,
    NOTE_G, NOTE_G_SHARP,
    NOTE_A,
    NOTE_B_FLAT, NOTE_B,
    NOTE_SILENT
};
typedef enum _Note Note;

// Enharmonics
#define NOTE_D_FLAT NOTE_C_SHARP
#define NOTE_E_FLAT NOTE_D_SHARP
#define NOTE_G_FLAT NOTE_F_SHARP
#define NOTE_A_FLAT NOTE_G_SHARP
#define NOTE_C_FLAT NOTE_B
#define NOTE_F_FLAT NOTE_E
#define NOTE_A_SHARP NOTE_B_FLAT
#define NOTE_E_SHARP NOTE_F
#define NOTE_B_SHARP NOTE_C

enum _NoteProgress { NOTE_START, NOTE_PLAYING, NOTE_FINISHED };
typedef enum _NoteProgress NoteProgress;

/**
 * A complete note consists of a note name, octave, duration, and a state
 * variable to determine whether the note has been started, is in progress, or
 * has finished playing. Use an array of CompleteNotes to represent music.
 */
struct _CompleteNote
{
    Note note;
    int octave;
    SWTimer duration;
    NoteProgress noteProgress;
};
typedef struct _CompleteNote CompleteNote;

// Constructs a CompleteNote object
CompleteNote CompleteNote_construct(Note note, int octave, uint32_t duration);

// A half step is defined as the twelfth root of 2, as precomputed below. We use
// this to define all of the other notes as relative to a base note.
#define HALF_STEP       1.05946309436

/**
 * A buzzer object, implemented in the C object-oriented style. Construct a
 * Buzzer object by calling its constructor. Afterwards, make the buzzer play a
 * continuous note by using [Buzzer_playRawNote()] function, and silence the
 * buzzer by using the [Buzzer_muteSound()] function.
 */
struct _Buzzer
{
    Timer_A_PWMConfig config;
    double referenceNotes[NUM_NOTES][NUM_OCTAVES];
};
typedef struct _Buzzer Buzzer;

// Constructs a new buzzer object
Buzzer Buzzer_construct();

// Make a buzzer start playing a note
void Buzzer_playRawNote(Buzzer* buzzer, Note note, int octave);

// Silence the buzzer if the buzzer is currently playing a note
void Buzzer_muteSound(Buzzer* buzzer);

// Polls for a complete note in a non-blocking fashion. Returns true if the note
// has finished playing.
bool Buzzer_playCompleteNote(Buzzer* buzzer, CompleteNote* completeNote);

#endif /* HAL_BUZZER_H_ */
