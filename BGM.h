/*
 * BGM.h
 *
 *  Created on: Nov 5, 2021
 *      Author: skybl
 */

#ifndef BGM_H_
#define BGM_H_

#include <Music/Song.h>

#define MM2_STAGECLEAR_INDEX 0
#define MM2_PASSWORD_INDEX 1
#define MM3_WEAPONGET_INDEX 2
#define MM5_GRAVITYMANSTAGE_INDEX 3

Song Song_MM2StageClear_construct();
Song Song_MM2Password_construct();
Song Song_MM3WeaponGet_construct();
Song Song_MM5GravityManStage_construct();

#endif /* BGM_H_ */
