/*
 * Graphics.c
 *
 *  Created on: Dec 30, 2019
 *      Author: Matthew Zhong
 */

#include <HAL/Graphics.h>

GFX GFX_construct(uint32_t defaultForeground, uint32_t defaultBackground)
{
    GFX gfx;

    gfx.defaultForeground = defaultForeground;
    gfx.defaultBackground = defaultBackground;

    Crystalfontz128x128_Init();
    Crystalfontz128x128_SetOrientation(LCD_ORIENTATION_UP);

    Graphics_initContext(&gfx.context, &g_sCrystalfontz128x128, &g_sCrystalfontz128x128_funcs);
    Graphics_setFont(&gfx.context, &g_sFontFixed6x8);

    GFX_resetColors(&gfx);
    GFX_clear(&gfx);

    return gfx;
}

void GFX_resetColors(GFX* gfx)
{
    gfx->foreground = gfx->defaultForeground;
    gfx->background = gfx->defaultBackground;

    Graphics_setForegroundColor(&gfx->context, gfx->defaultForeground);
    Graphics_setBackgroundColor(&gfx->context, gfx->defaultBackground);
}

void GFX_clear(GFX* gfx)
{
    Graphics_clearDisplay(&gfx->context);
}

void GFX_print(GFX* gfx, char* string, int row, int col)
{
    int yPosition = row * Graphics_getFontHeight(gfx->context.font);
    int xPosition = col * Graphics_getFontMaxWidth(gfx->context.font);

    Graphics_drawString(&gfx->context, (int8_t*) string, -1, xPosition, yPosition, OPAQUE_TEXT);
}

void GFX_setForeground(GFX* gfx, uint32_t foreground)
{
    gfx->foreground = foreground;
    Graphics_setForegroundColor(&gfx->context, foreground);
}

void GFX_setBackground(GFX* gfx, uint32_t background)
{
    gfx->background = background;
    Graphics_setBackgroundColor(&gfx->context, background);
}

void GFX_drawSolidCircle(GFX* gfx, int x, int y, int radius)
{
    Graphics_fillCircle(&gfx->context, x, y, radius);
}

void GFX_drawHollowCircle(GFX* gfx, int x, int y, int radius)
{
    Graphics_drawCircle(&gfx->context, x, y, radius);
}

void GFX_removeSolidCircle(GFX* gfx, int x, int y, int radius)
{
    uint32_t oldForegroundColor = gfx->foreground;
    GFX_setForeground(gfx, gfx->background);
    GFX_drawSolidCircle(gfx, x, y, radius);
    GFX_setForeground(gfx, oldForegroundColor);
}

void GFX_removeHollowCircle(GFX* gfx, int x, int y, int radius)
{
    uint32_t oldForegroundColor = gfx->foreground;
    GFX_setForeground(gfx, gfx->background);
    GFX_drawHollowCircle(gfx, x, y, radius);
    GFX_setForeground(gfx, oldForegroundColor);
}
