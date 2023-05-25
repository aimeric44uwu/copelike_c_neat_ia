/*
** EPITECH PROJECT, 2022
** neat_ia
** File description:
** draw_element.c
*/

#include "my.h"

void draw_background(programm_t *programm)
{
    sfRenderWindow_drawSprite(WIND, BG_SP, NULL);
    sfRenderWindow_drawSprite(WIND, BG_COL_SP, NULL);
    sfRenderWindow_drawSprite(WIND, BG_SP_LID, NULL);
}

void draw_cars(programm_t *programm)
{
    for (int i = 0; i < NBCAR; i++)
        sfRenderWindow_drawSprite(WIND, CAR_STSP, NULL);
}
