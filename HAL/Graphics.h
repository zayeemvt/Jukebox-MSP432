/*
 * Graphics.h
 *
 *  Created on: Dec 30, 2019
 *      Author: Matthew Zhong
 */

#ifndef HAL_GRAPHICS_H_
#define HAL_GRAPHICS_H_

#include <HAL/LcdDriver/Crystalfontz128x128_ST7735.h>
#include <ti/devices/msp432p4xx/driverlib/driverlib.h>
#include <ti/grlib/grlib.h>

#define FG_COLOR GRAPHICS_COLOR_WHITE
#define BG_COLOR GRAPHICS_COLOR_BLACK

struct _GFX
{
    Graphics_Context context;
    uint32_t foreground;
    uint32_t background;
    uint32_t defaultForeground;
    uint32_t defaultBackground;
};
typedef struct _GFX GFX;

GFX GFX_construct();

void GFX_resetColors(GFX* gfx);
void GFX_clear(GFX* gfx);

void GFX_print(GFX* gfx, char* string, int row, int col);
void GFX_setForeground(GFX* gfx, uint32_t foreground);
void GFX_setBackground(GFX* gfx, uint32_t background);

void GFX_drawSolidCircle(GFX* gfx, int x, int y, int radius);
void GFX_drawHollowCircle(GFX* gfx, int x, int y, int radius);

void GFX_removeSolidCircle(GFX* gfx, int x, int y, int radius);
void GFX_removeHollowCircle(GFX* gfx, int x, int y, int radius);

#endif /* HAL_GRAPHICS_H_ */
