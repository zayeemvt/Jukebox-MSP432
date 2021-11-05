/*
 * BGM.c
 *
 *  Created on: Nov 5, 2021
 *      Author: skybl
 */

#include <BGM.h>

Song Song_Test_construct() {
    SongNote notes[8] =
    {
     {NOTE_C, 4, QUARTER_NOTE},
     {NOTE_D, 4, QUARTER_NOTE},
     {NOTE_E, 4, QUARTER_NOTE},
     {NOTE_F, 4, QUARTER_NOTE},
     {NOTE_G, 4, QUARTER_NOTE},
     {NOTE_A, 4, QUARTER_NOTE},
     {NOTE_B, 4, QUARTER_NOTE},
     {NOTE_C, 5, QUARTER_NOTE}
    };

    Song song = Song_construct(120, notes, 8, true, 0);

    return song;
}

Song Song_Test1_construct() {
    SongNote notes[8] =
    {
     {NOTE_G, 4, QUARTER_NOTE},
     {NOTE_A, 4, QUARTER_NOTE},
     {NOTE_B, 4, QUARTER_NOTE},
     {NOTE_C, 5, QUARTER_NOTE},
     {NOTE_D, 5, QUARTER_NOTE},
     {NOTE_E, 5, QUARTER_NOTE},
     {NOTE_F_SHARP, 5, QUARTER_NOTE},
     {NOTE_G, 5, QUARTER_NOTE},
    };

    Song song = Song_construct(120, notes, 8, true, 0);

    return song;
}

Song Song_Test2_construct() {
    SongNote notes[8] =
    {
     {NOTE_D, 4, QUARTER_NOTE},
     {NOTE_E, 4, QUARTER_NOTE},
     {NOTE_F_SHARP, 4, QUARTER_NOTE},
     {NOTE_G, 4, QUARTER_NOTE},
     {NOTE_A, 4, QUARTER_NOTE},
     {NOTE_B, 4, QUARTER_NOTE},
     {NOTE_C_SHARP, 5, QUARTER_NOTE},
     {NOTE_D, 5, QUARTER_NOTE},
    };

    Song song = Song_construct(120, notes, 8, true, 0);

    return song;
}

Song Song_Test3_construct() {
    SongNote notes[8] =
    {
     {NOTE_A, 4, QUARTER_NOTE},
     {NOTE_B, 4, QUARTER_NOTE},
     {NOTE_C_SHARP, 5, QUARTER_NOTE},
     {NOTE_D, 5, QUARTER_NOTE},
     {NOTE_E, 5, QUARTER_NOTE},
     {NOTE_F_SHARP, 5, QUARTER_NOTE},
     {NOTE_G_SHARP, 5, QUARTER_NOTE},
     {NOTE_A, 5, QUARTER_NOTE},
    };

    Song song = Song_construct(120, notes, 8, true, 0);

    return song;
}
