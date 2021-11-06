/* DriverLib Includes */
#include <Application_jukebox.h>
#include <ti/devices/msp432p4xx/driverlib/driverlib.h>

/* Standard Includes */
#include <stdint.h>
#include <stdbool.h>
#include <string.h>
#include <stdio.h>

/* HAL and Application includes */
#include <HAL/HAL.h>
#include <HAL/Timer.h>

/**
 * The main entry point of your project. The main function should immediately
 * stop the Watchdog timer, call the Application constructor, and then
 * repeatedly call the main super-loop function. The Application constructor
 * should be responsible for initializing all hardware components as well as all
 * other finite state machines you choose to use in this project.
 *
 * THIS FUNCTION IS ALREADY COMPLETE. Unless you want to temporarily experiment
 * with some behavior of a code snippet you may have, we DO NOT RECOMMEND
 * modifying this function in any way.
 */
int main(void)
{
    // Stop Watchdog Timer - THIS SHOULD ALWAYS BE THE FIRST LINE OF YOUR MAIN
    WDT_A_holdTimer();

    // Initialize the system clock and background hardware timer, used to enable
    // software timers to time their measurements properly.
    InitSystemTiming();

    // Initialize the main Application object. This function also needs to
    // call functions which initialize the HAL and Graphics objects.
    JukeboxApp app = JukeboxApp_construct();

    HAL hal = HAL_construct();

    Jukebox_changeSong(&hal.buzzer, &app.jukebox, MM2_STAGECLEAR_INDEX);
    // Main super-loop! In a polling architecture, this function should call
    // your main FSM function over and over.
    while (true) {
        JukeboxApp_loop(&app, &hal);
        HAL_refresh(&hal);

    }
}

/**
 * The main constructor for your application. This function initializes each HAL
 * member of the Application object, followed by setting up each of the FSMs
 * which demo components of the board.
 *
 * @return a completely initialized Application object
 */
JukeboxApp JukeboxApp_construct()
{
    // The Application object to initialize
    JukeboxApp app;

    // Initialization of FSMs inside of main project
    // Initializes FSM variables
//    app.note = NOTE_C;
//    app.octave = 4;
//    app.completeNote = CompleteNote_construct(NOTE_SILENT, app.octave, 500);
//    app.playSilent = false;
    app.mute = false;

    app.gfx = GFX_construct(GRAPHICS_COLOR_WHITE, GRAPHICS_COLOR_BLACK);

//    GFX_print(&app.gfx, "play/pause: ", 2, 1);
//    GFX_print(&app.gfx, "joystick push btn", 3, 3);
//
//    GFX_print(&app.gfx, "-/+ octave: ", 5, 1);
//    GFX_print(&app.gfx, "Boosterpack S1/S2", 6, 3);
//
//    GFX_print(&app.gfx, "-/+ note: ", 9, 1);
//    GFX_print(&app.gfx, "Launchpad S1/S2", 10, 3);
//
//    // Draw the flavor text for the buzzer
//
//    GFX_print(&app.gfx, "Now playing:", 12, 1);

    app.jukebox = Jukebox_construct();
    JukeboxApp_addSongs(&app.jukebox);

    // Return the completed Application struct to the user
    return app;
}

void JukeboxApp_loop(JukeboxApp* app, HAL *hal_p)
{
    // Toggle the buzzer (pause/unpause) when Boosterpack joystick button is tapped.
    if (Button_isTapped(&hal_p->boosterpackJS)) {
        app->mute = !app->mute;
    }

    // Main FSM logic which beeps for either silence or the next note when ready.
//    if (Buzzer_playCompleteNote(&hal_p->buzzer, &app->completeNote)) {
//        app->playSilent = !app->playSilent;
//        if (app->playSilent || app->mute) {
//            app->completeNote = CompleteNote_construct(NOTE_SILENT, app->octave, 500);
//        }
//        else {
//            app->completeNote = CompleteNote_construct(app->note, app->octave, 500);
//        }
//    }

    if (app->mute) {
        Buzzer_playRawNote(&hal_p->buzzer, NOTE_SILENT, 0);
    }
    else {
        Jukebox_playSong(&hal_p->buzzer, &app->jukebox);
    }

    if (Button_isTapped(&hal_p->launchpadS1)) {
        Jukebox_changeSong(&hal_p->buzzer, &app->jukebox, MM2_STAGECLEAR_INDEX);
    }

    if (Button_isTapped(&hal_p->launchpadS2)) {
        Jukebox_changeSong(&hal_p->buzzer, &app->jukebox, MM2_PASSWORD_INDEX);
    }

    if (Button_isTapped(&hal_p->boosterpackS1)) {
        Jukebox_changeSong(&hal_p->buzzer, &app->jukebox, MM3_WEAPONGET_INDEX);
    }

    if (Button_isTapped(&hal_p->boosterpackS2)) {
        Jukebox_changeSong(&hal_p->buzzer, &app->jukebox, MM5_GRAVITYMANSTAGE_INDEX);
    }
    // Increment octave when BoosterPack S2 is tapped up, with a ceiling cap
//    if (Button_isTapped(&hal_p->boosterpackS2) && app->octave < NUM_OCTAVES - 1) {
//        app->octave++;
//    }
//
//    // Decrement octave when BoosterPack S1 is tapped, with a floor cap
//    if (Button_isTapped(&hal_p->boosterpackS1) && app->octave > OCTAVE_LOW) {
//        app->octave--;
//    }
//
//    // Lower the note when the Launchpad S1 is tapped, capped at NOTE_C
//    if (Button_isTapped(&hal_p->launchpadS1) && app->note != NOTE_C) {
//        app->note--;
//    }
//
//    // Raise the note when Launchpad S2 is tapped, capped at NOTE_B
//    if (Button_isTapped(&hal_p->launchpadS2) && app->note != NOTE_B) {
//        app->note++;
//    }

//    // Print the next note. Use a note mapping to determine what character each
//    // next note should have, and print the according note text.
//    char noteLetterMap[]     = "CCDDEFFGGABB";
//    char noteAccidentalMap[] = " # #  # # b ";
//
//    char buffer[5];
//    buffer[0] = noteLetterMap[app->note];
//    buffer[1] = noteAccidentalMap[app->note];
//    buffer[2] = ' ';
//    buffer[3] = app->octave + '0';
//    buffer[4] = '\0';
//
//    GFX_print(&app->gfx, buffer, 13, 3);
}

void JukeboxApp_addSongs(Jukebox *jukebox) {
    Song testSong = Song_MM2StageClear_construct();
    Jukebox_addSong(jukebox, testSong);

    testSong = Song_MM2Password_construct();
    Jukebox_addSong(jukebox, testSong);

    testSong = Song_MM3WeaponGet_construct();
    Jukebox_addSong(jukebox, testSong);

    testSong = Song_MM5GravityManStage_construct();
    Jukebox_addSong(jukebox, testSong);
}



