/*
 * Song.c
 *
 *  Created on: Nov 5, 2021
 *      Author: skybl
 */

#include <Music/Song.h>

// Private API functions
CompleteNote Song_makeNextNote(Song *song);
uint32_t Song_calcNoteDuration(uint16_t tempo, NoteDuration duration, uint8_t value);

// Public
Song Song_construct(uint16_t tempo, SongNote *notes, uint16_t length, bool loop, uint16_t loop_point) {
    Song song;

    song.tempo = tempo;
    song.note_index = 0;
    song.length = length;
    song.loop = loop;
    song.loop_point = loop_point;
    song.song_progress = READY;

    int i;
    for (i = 0; i < length; i++) {
        song.notes[i] = notes[i];
    }

    return song;
}

bool Song_playSong(Buzzer *buzzer, Song *song) {
    switch(song->song_progress) {
    case READY:
        song->note_index = 0;
        song->current_note = Song_makeNextNote(song);

        song->song_progress = PLAYING;
        break;

    case PLAYING:
        if (Buzzer_playCompleteNote(buzzer, &song->current_note)) {
            Buzzer_playRawNote(buzzer, NOTE_SILENT, 0);
            song->song_progress = NEXT_NOTE;
        }
        break;

    case NEXT_NOTE:
        song->note_index++;

        if (song->note_index >= song->length) {
            if (song->loop) {
                song->note_index = song->loop_point;
                song->current_note = Song_makeNextNote(song);
                song->song_progress = PLAYING;
            }
            else {
                song->song_progress = FINISHED;
                Buzzer_playRawNote(buzzer, NOTE_SILENT, 0);
            }
        }
        else {
            song->current_note = Song_makeNextNote(song);
            song->song_progress = PLAYING;
        }
        break;

    case FINISHED:
        return true;
    }

    return false;
}

CompleteNote Song_makeNextNote(Song *song) {
    SongNote note_to_play = song->notes[song->note_index];
    uint32_t duration = Song_calcNoteDuration(song->tempo, note_to_play.duration, note_to_play.value);
    CompleteNote new_note = CompleteNote_construct(note_to_play.note, note_to_play.octave, duration);
    return new_note;
}

uint32_t Song_calcNoteDuration(uint16_t tempo, NoteDuration division, uint8_t value) {
    // Numerator: 4 beats per whole note * (60 * 1000) milliseconds per minute
    // Denominator: [tempo] beats per minute * [division] sixteenth notes per whole note
    // Multiply by [value] number of tied notes

    uint32_t time_ms = (4 * 1000 * 60) / (tempo * division) * value;
    return time_ms;
}
