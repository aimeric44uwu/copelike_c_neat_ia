/*
** EPITECH PROJECT, 2022
** neat_ia
** File description:
** mouse.c
*/

#include "my.h"

void mouse_moved(programm_t *programm)
{
    if (EVNT.mouseMove.x > 0 && EVNT.mouseMove.x < WINDOW_W)
        MOUSE_X = EVNT.mouseMove.x;
    if (EVNT.mouseMove.y > 0 && EVNT.mouseMove.y < WINDOW_H)
        MOUSE_Y = EVNT.mouseMove.y;
    sfView_setCenter(MAIN_VIEW,
    (sfVector2f){(WINDOW_CENTER_Y) - (NEW_VIEW_X),
    (WINDOW_CENTER_Y) - (NEW_VIEW_Y)});
}
