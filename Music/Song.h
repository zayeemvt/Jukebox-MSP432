/*
 * Song.h
 *
 *  Created on: Nov 5, 2021
 *      Author: skybl
 */

#ifndef HAL_SONG_H_
#define HAL_SONG_H_

#include <HAL/Buzzer.h>

#define MAX_SONG_NOTES 200

typedef enum {
    READY, PLAYING, NEXT_NOTE, FINISHED
} SongProgress;

typedef enum {
    WHOLE_NOTE = 1,
    HALF_NOTE = 2,
    QUARTER_NOTE = 4,
    EIGHTH_NOTE = 8,
    SIXTEENTH_NOTE = 16,
    EIGHTH_TRIPLE = 12
} NoteDuration;

typedef struct {
    Note note;
    int octave;
    NoteDuration duration;
    uint8_t value;
} SongNote;

typedef struct {
    uint16_t tempo;
    SongNote notes[MAX_SONG_NOTES];
    uint16_t length;

    uint16_t note_index;
    CompleteNote current_note;

    SongProgress song_progress;

    bool loop;
    uint16_t loop_point;
} Song;

Song Song_construct(uint16_t tempo, SongNote *notes, uint16_t length, bool loop, uint16_t loop_point);
bool Song_playSong(Buzzer *buzzer, Song *song);

#endif /* HAL_SONG_H_ */
