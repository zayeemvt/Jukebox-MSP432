/*
 * Jukebox.h
 *
 *  Created on: Nov 5, 2021
 *      Author: skybl
 */

#ifndef JUKEBOX_H_
#define JUKEBOX_H_

#include <Music/Song.h>

#define MAX_SONGS 10

typedef struct {
    Song song_list[MAX_SONGS];
    uint16_t song_index;
    uint16_t num_songs;
    Song current_song;
} Jukebox;

Jukebox Jukebox_construct();
bool Jukebox_playSong(Buzzer *buzzer, Jukebox *jukebox);
bool Jukebox_addSong(Jukebox *jukebox, Song song);
bool Jukebox_changeSong(Buzzer *buzzer, Jukebox *jukebox, uint16_t song_index);

#endif /* JUKEBOX_H_ */
