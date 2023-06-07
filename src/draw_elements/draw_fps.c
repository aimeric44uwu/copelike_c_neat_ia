/*
** EPITECH PROJECT, 2022
** neat_ia
** File description:
** draw_fps.c
*/

#include "my.h"

void update_fps(programm_t *programm)
{
    FPS++;
    FPS_TIME = sfClock_getElapsedTime(FPS_CLK);
    FPS_SEC = FPS_TIME.microseconds / 1000000.0;
    if (FPS_SEC > 1) {
        FPS_STR = int_to_char_array("fps: ", FPS);
        sfText_setString(FPS_TXT, FPS_STR);
        sfClock_restart(FPS_CLK);
        FPS = 0;
    }
    sfRenderWindow_drawText(WIND, FPS_TXT, NULL);
}
