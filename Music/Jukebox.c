/*
 * Jukebox.c
 *
 *  Created on: Nov 5, 2021
 *      Author: skybl
 */

#include <Music/Jukebox.h>

Jukebox Jukebox_construct() {
    Jukebox jukebox;

    jukebox.song_index = 0;
    jukebox.num_songs = 0;

    return jukebox;
}

bool Jukebox_playSong(Buzzer *buzzer, Jukebox *jukebox) {
    if (jukebox->num_songs > 0) {
        return Song_playSong(buzzer, &jukebox->current_song);
    }

    return false;
}

bool Jukebox_addSong(Jukebox *jukebox, Song song) {
    if (jukebox->num_songs < MAX_SONGS) {
        jukebox->song_list[jukebox->num_songs] = song;
        jukebox->num_songs++;

        return true;
    }

    return false;
}

bool Jukebox_changeSong(Buzzer *buzzer, Jukebox *jukebox, uint16_t song_index) {
    if (song_index < jukebox->num_songs) {
        jukebox->song_index = song_index;
        jukebox->current_song = jukebox->song_list[jukebox->song_index];
        Buzzer_playRawNote(buzzer, NOTE_SILENT, 0);
        return true;
    }

    return false;
}
