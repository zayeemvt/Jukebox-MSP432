/*
 * BGM.c
 *
 *  Created on: Nov 5, 2021
 *      Author: skybl
 */

#include <BGM.h>

Song Song_MM2Password_construct() {
    // Mega Man 2 - Password Theme
    // Composer: Takashi Tateishi
    // Arranged by Yale Scores on YouTube

    SongNote notes[] =
    {
     // Measure 1 - 5 notes
     {NOTE_G_SHARP, 5, QUARTER_NOTE, 1},
     {NOTE_G_SHARP, 5, QUARTER_NOTE, 1},
     {NOTE_F_SHARP, 5, EIGHTH_TRIPLE, 2},
     {NOTE_F_SHARP, 5, EIGHTH_TRIPLE, 3},
     {NOTE_F_SHARP, 5, EIGHTH_TRIPLE, 1},

     // Measure 2 - 8 notes
     {NOTE_F_SHARP, 5, EIGHTH_TRIPLE, 2},
     {NOTE_F_SHARP, 5, EIGHTH_TRIPLE, 1},
     {NOTE_SILENT, 0, EIGHTH_TRIPLE, 2},
     {NOTE_E, 5, EIGHTH_TRIPLE, 3},
     {NOTE_E, 5, EIGHTH_TRIPLE, 1},
     {NOTE_E, 5, EIGHTH_TRIPLE, 1},
     {NOTE_E, 5, EIGHTH_TRIPLE, 1},
     {NOTE_F_SHARP, 5, EIGHTH_TRIPLE, 1}
    };

    Song song = Song_construct(132, notes, 13, true, 0);

    return song;
}

Song Song_MM3WeaponGet_construct() {
    // Mega Man 3 - Weapon Get Theme
    // Composer: Yasuaki "Bun Bun" Fujita
    // Arranged by Dart on NinSheetMusic

    SongNote notes[] =
    {
     // Section A - total 17 notes
     // Measure 1 - 6 notes
     {NOTE_D_FLAT, 5, EIGHTH_NOTE, 3},
     {NOTE_B, 4, SIXTEENTH_NOTE, 1},
     {NOTE_A, 4, SIXTEENTH_NOTE, 1},
     {NOTE_B, 4, EIGHTH_NOTE, 3},
     {NOTE_A, 4, SIXTEENTH_NOTE, 1},
     {NOTE_A_FLAT, 4, SIXTEENTH_NOTE, 1},

     // Measure 2 - 7 notes
     {NOTE_A, 4, EIGHTH_NOTE, 3},
     {NOTE_A_FLAT, 4, SIXTEENTH_NOTE, 1},
     {NOTE_F_SHARP, 4, SIXTEENTH_NOTE, 1},
     {NOTE_A_FLAT, 4, EIGHTH_NOTE, 1},
     {NOTE_F_SHARP, 4, EIGHTH_NOTE, 1},
     {NOTE_E, 4, EIGHTH_NOTE, 1},
     {NOTE_F_SHARP, 4, EIGHTH_NOTE, 1},

     // Measure 3 - 4 notes
     {NOTE_F_SHARP, 4, EIGHTH_NOTE, 1},
     {NOTE_D_FLAT, 5, SIXTEENTH_NOTE, 1},
     {NOTE_B, 4, SIXTEENTH_NOTE, 1},
     {NOTE_D_FLAT, 5, QUARTER_NOTE, 7},

     // Section A repeat - total 17 notes
     // Measure 4
     {NOTE_D_FLAT, 5, EIGHTH_NOTE, 3},
     {NOTE_B, 4, SIXTEENTH_NOTE, 1},
     {NOTE_A, 4, SIXTEENTH_NOTE, 1},
     {NOTE_B, 4, EIGHTH_NOTE, 3},
     {NOTE_A, 4, SIXTEENTH_NOTE, 1},
     {NOTE_A_FLAT, 4, SIXTEENTH_NOTE, 1},

     // Measure 5
     {NOTE_A, 4, EIGHTH_NOTE, 3},
     {NOTE_A_FLAT, 4, SIXTEENTH_NOTE, 1},
     {NOTE_F_SHARP, 4, SIXTEENTH_NOTE, 1},
     {NOTE_A_FLAT, 4, EIGHTH_NOTE, 1},
     {NOTE_F_SHARP, 4, EIGHTH_NOTE, 1},
     {NOTE_E, 4, EIGHTH_NOTE, 1},
     {NOTE_F_SHARP, 4, EIGHTH_NOTE, 1},

     // Measure 6
     {NOTE_F_SHARP, 4, EIGHTH_NOTE, 1},
     {NOTE_D_FLAT, 5, SIXTEENTH_NOTE, 1},
     {NOTE_B, 4, SIXTEENTH_NOTE, 1},
     {NOTE_D_FLAT, 5, QUARTER_NOTE, 7},

     // Section B - 48 notes
     // Measure 7 - 7 notes
     {NOTE_F_SHARP, 4, EIGHTH_NOTE, 3},
     {NOTE_F_SHARP, 4, SIXTEENTH_NOTE, 1},
     {NOTE_D_FLAT, 5, SIXTEENTH_NOTE, 1},
     {NOTE_B, 4, EIGHTH_NOTE, 1},
     {NOTE_A, 4, EIGHTH_NOTE, 1},
     {NOTE_A_FLAT, 4, EIGHTH_NOTE, 1},
     {NOTE_A, 4, EIGHTH_NOTE, 1},

     // Measure 8 - 5 notes
     {NOTE_F_SHARP, 4, QUARTER_NOTE, 1},
     {NOTE_A_FLAT, 4, SIXTEENTH_NOTE, 3},
     {NOTE_A, 4, SIXTEENTH_NOTE, 1},
     {NOTE_A_FLAT, 4, EIGHTH_NOTE, 1},
     {NOTE_F_SHARP, 4, EIGHTH_NOTE, 3},

     // Measure 9 - 7 notes
     {NOTE_F_SHARP, 4, EIGHTH_NOTE, 3},
     {NOTE_F_SHARP, 4, SIXTEENTH_NOTE, 1},
     {NOTE_D_FLAT, 5, SIXTEENTH_NOTE, 1},
     {NOTE_E, 5, EIGHTH_NOTE, 1},
     {NOTE_D, 5, EIGHTH_NOTE, 1},
     {NOTE_D_FLAT, 5, EIGHTH_NOTE, 1},
     {NOTE_B, 4, EIGHTH_NOTE, 1},

     // Measure 10 - 5 notes
     {NOTE_D_FLAT, 5, QUARTER_NOTE, 1},
     {NOTE_D, 5, SIXTEENTH_NOTE, 3},
     {NOTE_E, 5, SIXTEENTH_NOTE, 1},
     {NOTE_D, 5, EIGHTH_NOTE, 1},
     {NOTE_D_FLAT, 5, EIGHTH_NOTE, 3},

     // Measure 11 - 7 notes
     {NOTE_F_SHARP, 4, EIGHTH_NOTE, 3},
     {NOTE_F_SHARP, 4, SIXTEENTH_NOTE, 1},
     {NOTE_D_FLAT, 5, SIXTEENTH_NOTE, 1},
     {NOTE_B, 4, EIGHTH_NOTE, 1},
     {NOTE_A, 4, EIGHTH_NOTE, 1},
     {NOTE_A_FLAT, 4, EIGHTH_NOTE, 1},
     {NOTE_A, 4, EIGHTH_NOTE, 1},

     // Measure 12 - 5 notes
     {NOTE_F_SHARP, 4, QUARTER_NOTE, 1},
     {NOTE_A_FLAT, 4, SIXTEENTH_NOTE, 3},
     {NOTE_A, 4, SIXTEENTH_NOTE, 1},
     {NOTE_A_FLAT, 4, EIGHTH_NOTE, 1},
     {NOTE_F_SHARP, 4, EIGHTH_NOTE, 3},

     // Measure 13 - 7 notes
     {NOTE_F_SHARP, 5, EIGHTH_NOTE, 3},
     {NOTE_F_SHARP, 5, SIXTEENTH_NOTE, 1},
     {NOTE_A, 5, SIXTEENTH_NOTE, 1},
     {NOTE_A_FLAT, 5, EIGHTH_NOTE, 1},
     {NOTE_E, 5, EIGHTH_NOTE, 1},
     {NOTE_F_SHARP, 5, EIGHTH_NOTE, 1},
     {NOTE_A_FLAT, 5, EIGHTH_NOTE, 1},

     // Measure 14 - 5 notes
     {NOTE_F_SHARP, 5, QUARTER_NOTE, 1},
     {NOTE_A_FLAT, 5, SIXTEENTH_NOTE, 3},
     {NOTE_A, 5, SIXTEENTH_NOTE, 1},
     {NOTE_A_FLAT, 5, EIGHTH_NOTE, 1},
     {NOTE_F_SHARP, 5, EIGHTH_NOTE, 3},
    };

    Song song = Song_construct(150, notes, 82, true, 0);

    return song;
}

Song Song_MM2StageClear_construct() {
    // Mega Man 2 - Stage Clear Theme
    // Composer: Takashi Tateishi
    // Arranged by Gabriel "Gabb" Abbrugiati on YouTube

    SongNote notes[] =
    {
     // Measure 1 - 5 notes
     {NOTE_C_SHARP, 5, SIXTEENTH_NOTE, 1},
     {NOTE_C_SHARP, 5, SIXTEENTH_NOTE, 1},
     {NOTE_SILENT, 0, EIGHTH_NOTE, 1},
     {NOTE_D_SHARP, 5, SIXTEENTH_NOTE, 1},
     {NOTE_D_SHARP, 5, SIXTEENTH_NOTE, 1},
     {NOTE_SILENT, 0, EIGHTH_NOTE, 1},
     {NOTE_E, 5, SIXTEENTH_NOTE, 1},
     {NOTE_E, 5, SIXTEENTH_NOTE, 1},
     {NOTE_SILENT, 0, EIGHTH_NOTE, 1},
     {NOTE_F_SHARP, 5, SIXTEENTH_NOTE, 1},
     {NOTE_E, 5, SIXTEENTH_NOTE, 1},
     {NOTE_F_SHARP, 5, SIXTEENTH_NOTE, 1},
     {NOTE_G_SHARP, 5, SIXTEENTH_NOTE, 9}
    };

    Song song = Song_construct(150, notes, 13, false, 0);

    return song;
}

Song Song_MM5GravityManStage_construct() {
    // Mega Man 5 - Gravity Man Theme
    // Composer: Mari Yamaguchi
    // Arranged by Bowserdude729 on MuseScore
    // Additional credits to Yale Scores on YouTube

    SongNote notes[] =
    {
     // Intro - total 18 notes
     // Measure 1 + 2 - 4 notes
     {NOTE_SILENT, 0, QUARTER_NOTE, 1},
     {NOTE_F_SHARP, 5, SIXTEENTH_NOTE, 3},
     {NOTE_E, 5, SIXTEENTH_NOTE, 13},
     {NOTE_SILENT, 0, QUARTER_NOTE, 3},

     // Measure 3 + 4 - 4 notes
     {NOTE_SILENT, 0, QUARTER_NOTE, 1},
     {NOTE_B, 5, SIXTEENTH_NOTE, 3},
     {NOTE_A_SHARP, 5, SIXTEENTH_NOTE, 13},
     {NOTE_SILENT, 0, QUARTER_NOTE, 3},

     // Measure 5 + 6 - 4 notes
     {NOTE_SILENT, 0, QUARTER_NOTE, 1},
     {NOTE_F_SHARP, 5, SIXTEENTH_NOTE, 3},
     {NOTE_E, 5, SIXTEENTH_NOTE, 13},
     {NOTE_SILENT, 0, QUARTER_NOTE, 3},

     // Measure 7 - 6 notes
     {NOTE_SILENT, 0, EIGHTH_NOTE, 1},
     {NOTE_D_SHARP, 5, SIXTEENTH_NOTE, 1},
     {NOTE_C_SHARP, 5, SIXTEENTH_NOTE, 1},
     {NOTE_D_SHARP, 5, SIXTEENTH_NOTE, 1},
     {NOTE_E_SHARP, 5, EIGHTH_NOTE, 1},
     {NOTE_B, 5, SIXTEENTH_NOTE, 9},

     // Section A - total 37 notes
     // Measure 8 + 9 - 13 notes
     {NOTE_F_SHARP, 4, EIGHTH_NOTE, 1},
     {NOTE_E, 4, EIGHTH_NOTE, 1},
     {NOTE_F_SHARP, 4, EIGHTH_NOTE, 1},
     {NOTE_A, 4, EIGHTH_NOTE, 1},
     {NOTE_C_SHARP, 5, SIXTEENTH_NOTE, 3},
     {NOTE_C_SHARP, 5, SIXTEENTH_NOTE, 3},
     {NOTE_C_SHARP, 5, EIGHTH_NOTE, 2},
     {NOTE_B, 4, EIGHTH_NOTE, 1},
     {NOTE_SILENT, 0, EIGHTH_NOTE, 1},
     {NOTE_E, 4, QUARTER_NOTE, 1},
     {NOTE_F_SHARP, 4, EIGHTH_NOTE, 1},
     {NOTE_A, 4, EIGHTH_NOTE, 1},
     {NOTE_C_SHARP, 5, EIGHTH_NOTE, 1},

     // Measure 10 + 11 - 7 notes
     {NOTE_E, 5, SIXTEENTH_NOTE, 3},
     {NOTE_D_SHARP, 5, SIXTEENTH_NOTE, 3},
     {NOTE_B, 4, EIGHTH_NOTE, 1},
     {NOTE_D_SHARP, 5, SIXTEENTH_NOTE, 3},
     {NOTE_E, 5, SIXTEENTH_NOTE, 3},
     {NOTE_F_SHARP, 5, EIGHTH_NOTE, 1},
     {NOTE_B, 4, WHOLE_NOTE, 1},

     // Measure 12 + 13 - 12 notes
     {NOTE_SILENT, 0, EIGHTH_NOTE, 1},
     {NOTE_E, 4, EIGHTH_NOTE, 1},
     {NOTE_F_SHARP, 4, EIGHTH_NOTE, 1},
     {NOTE_C_SHARP, 5, EIGHTH_NOTE, 1},
     {NOTE_SILENT, 0, EIGHTH_NOTE, 1},
     {NOTE_C_SHARP, 5, EIGHTH_NOTE, 1},
     {NOTE_SILENT, 0, EIGHTH_NOTE, 1},
     {NOTE_C_SHARP, 5, EIGHTH_NOTE, 2},
     {NOTE_D, 5, QUARTER_NOTE, 1},
     {NOTE_C_SHARP, 5, QUARTER_NOTE, 1},
     {NOTE_D, 5, QUARTER_NOTE, 1},
     {NOTE_C_SHARP, 5, EIGHTH_NOTE, 1},

     // Measure 14 + 15 - 5 notes
     {NOTE_C, 5, EIGHTH_NOTE, 3},
     {NOTE_G_SHARP, 4, HALF_NOTE, 1},
     {NOTE_A_SHARP, 4, SIXTEENTH_NOTE, 1},
     {NOTE_C, 5, SIXTEENTH_NOTE, 1},
     {NOTE_C_SHARP, 5, WHOLE_NOTE, 1},

     // Section A repeat - total 37 notes
     // Measure 16 + 17
     {NOTE_F_SHARP, 4, EIGHTH_NOTE, 1},
     {NOTE_E, 4, EIGHTH_NOTE, 1},
     {NOTE_F_SHARP, 4, EIGHTH_NOTE, 1},
     {NOTE_A, 4, EIGHTH_NOTE, 1},
     {NOTE_C_SHARP, 5, SIXTEENTH_NOTE, 3},
     {NOTE_C_SHARP, 5, SIXTEENTH_NOTE, 3},
     {NOTE_C_SHARP, 5, EIGHTH_NOTE, 2},
     {NOTE_B, 4, EIGHTH_NOTE, 1},
     {NOTE_SILENT, 0, EIGHTH_NOTE, 1},
     {NOTE_E, 4, QUARTER_NOTE, 1},
     {NOTE_F_SHARP, 4, EIGHTH_NOTE, 1},
     {NOTE_A, 4, EIGHTH_NOTE, 1},
     {NOTE_C_SHARP, 5, EIGHTH_NOTE, 1},

     // Measure 18 + 19
     {NOTE_E, 5, SIXTEENTH_NOTE, 3},
     {NOTE_D_SHARP, 5, SIXTEENTH_NOTE, 3},
     {NOTE_B, 4, EIGHTH_NOTE, 1},
     {NOTE_D_SHARP, 5, SIXTEENTH_NOTE, 3},
     {NOTE_E, 5, SIXTEENTH_NOTE, 3},
     {NOTE_F_SHARP, 5, EIGHTH_NOTE, 1},
     {NOTE_B, 4, WHOLE_NOTE, 1},

     // Measure 20 + 21
     {NOTE_SILENT, 0, EIGHTH_NOTE, 1},
     {NOTE_E, 4, EIGHTH_NOTE, 1},
     {NOTE_F_SHARP, 4, EIGHTH_NOTE, 1},
     {NOTE_C_SHARP, 5, EIGHTH_NOTE, 1},
     {NOTE_SILENT, 0, EIGHTH_NOTE, 1},
     {NOTE_C_SHARP, 5, EIGHTH_NOTE, 1},
     {NOTE_SILENT, 0, EIGHTH_NOTE, 1},
     {NOTE_C_SHARP, 5, EIGHTH_NOTE, 2},
     {NOTE_D, 5, QUARTER_NOTE, 1},
     {NOTE_C_SHARP, 5, QUARTER_NOTE, 1},
     {NOTE_D, 5, QUARTER_NOTE, 1},
     {NOTE_C_SHARP, 5, EIGHTH_NOTE, 1},

     // Measure 22 + 23
     {NOTE_C, 5, EIGHTH_NOTE, 3},
     {NOTE_G_SHARP, 4, HALF_NOTE, 1},
     {NOTE_A_SHARP, 4, SIXTEENTH_NOTE, 1},
     {NOTE_C, 5, SIXTEENTH_NOTE, 1},
     {NOTE_C_SHARP, 5, WHOLE_NOTE, 1},

     // Section B - total 28 notes
     // Measure 24 + 25 + 26 + 27 - 12 notes
      {NOTE_G_SHARP, 5, EIGHTH_NOTE, 7},
      {NOTE_F_SHARP, 5, SIXTEENTH_NOTE, 1},
      {NOTE_G_SHARP, 5, SIXTEENTH_NOTE, 14},
      {NOTE_F_SHARP, 5, EIGHTH_NOTE, 1},
      {NOTE_G_SHARP, 5, QUARTER_NOTE, 1},
      {NOTE_F_SHARP, 5, EIGHTH_NOTE, 1},
      {NOTE_G_SHARP, 5, QUARTER_NOTE, 1},
      {NOTE_G_SHARP, 5, QUARTER_NOTE, 1},
      {NOTE_G_SHARP, 5, QUARTER_NOTE, 1},
      {NOTE_C_SHARP, 6, EIGHTH_NOTE, 1},
      {NOTE_D_SHARP, 6, EIGHTH_NOTE, 1},
      {NOTE_G_SHARP, 5, SIXTEENTH_NOTE, 11},

      // Measure 28 + 29 - 10 notes
      {NOTE_SILENT, 0, EIGHTH_NOTE, 1},
      {NOTE_F_SHARP, 4, EIGHTH_NOTE, 1},
      {NOTE_B, 4, EIGHTH_NOTE, 1},
      {NOTE_F_SHARP, 5, EIGHTH_NOTE, 2},
      {NOTE_E, 5, EIGHTH_NOTE, 2},
      {NOTE_B, 4, EIGHTH_NOTE, 1},
      {NOTE_C_SHARP, 5, EIGHTH_NOTE, 1},
      {NOTE_D, 5, EIGHTH_NOTE, 2},
      {NOTE_E, 5, EIGHTH_NOTE, 3},
      {NOTE_F_SHARP, 5, QUARTER_NOTE, 1},

      // Measure 30 + 31 - 6 notes
      {NOTE_G_SHARP, 5, QUARTER_NOTE, 3},
      {NOTE_F_SHARP, 5, QUARTER_NOTE, 1},
      {NOTE_D_SHARP, 5, QUARTER_NOTE, 1},
      {NOTE_E_SHARP, 5, QUARTER_NOTE, 1},
      {NOTE_F_SHARP, 5, QUARTER_NOTE, 1},
      {NOTE_G_SHARP, 5, QUARTER_NOTE, 1},

      // Section B repeat (alt.) - total 28 notes
      // Measure 32 + 33 + 34 + 35 - 12 notes
      {NOTE_G_SHARP, 5, EIGHTH_NOTE, 7},
      {NOTE_F_SHARP, 5, SIXTEENTH_NOTE, 1},
      {NOTE_G_SHARP, 5, SIXTEENTH_NOTE, 14},
      {NOTE_F_SHARP, 5, EIGHTH_NOTE, 1},
      {NOTE_G_SHARP, 5, QUARTER_NOTE, 1},
      {NOTE_F_SHARP, 5, EIGHTH_NOTE, 1},
      {NOTE_G_SHARP, 5, QUARTER_NOTE, 1},
      {NOTE_G_SHARP, 5, QUARTER_NOTE, 1},
      {NOTE_G_SHARP, 5, QUARTER_NOTE, 1},
      {NOTE_C_SHARP, 6, EIGHTH_NOTE, 1},
      {NOTE_D_SHARP, 6, EIGHTH_NOTE, 1},
      {NOTE_G_SHARP, 5, SIXTEENTH_NOTE, 11},

      // Measure 36 + 37 - 10 notes
      {NOTE_SILENT, 0, EIGHTH_NOTE, 1},
      {NOTE_F_SHARP, 4, EIGHTH_NOTE, 1},
      {NOTE_B, 4, EIGHTH_NOTE, 1},
      {NOTE_F_SHARP, 5, EIGHTH_NOTE, 2},
      {NOTE_E, 5, EIGHTH_NOTE, 2},
      {NOTE_B, 4, EIGHTH_NOTE, 1},
      {NOTE_C_SHARP, 5, EIGHTH_NOTE, 1},
      {NOTE_D, 5, EIGHTH_NOTE, 2},
      {NOTE_E, 5, EIGHTH_NOTE, 3},
      {NOTE_F_SHARP, 5, QUARTER_NOTE, 1},

      // Measure 38 + 39 - 6 notes
      {NOTE_G_SHARP, 5, QUARTER_NOTE, 3},
      {NOTE_F_SHARP, 5, QUARTER_NOTE, 1},
      {NOTE_D_SHARP, 5, QUARTER_NOTE, 1},
      {NOTE_G_SHARP, 5, QUARTER_NOTE, 1},
      {NOTE_A_SHARP, 5, QUARTER_NOTE, 1},
      {NOTE_C, 6, QUARTER_NOTE, 1},

      // Section C
      // Measure 40
      {NOTE_C_SHARP, 6, QUARTER_NOTE, 1},
      {NOTE_SILENT, 6, QUARTER_NOTE, 3},
    };

    Song song = Song_construct(140, notes, 150, true, 18);

    return song;
}
