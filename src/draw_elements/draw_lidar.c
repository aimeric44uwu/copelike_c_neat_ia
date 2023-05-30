/*
** EPITECH PROJECT, 2022
** neat_ia
** File description:
** draw_lidar.c
*/

#include "my.h"

void draw_lidar(programm_t *programm, int i)
{
    float left_rad_ray = (PI / 180) * ((CAR_ORI - LID_DEMIANG));
    float right_rad_ray = (PI / 180) * ((CAR_ORI + LID_DEMIANG));
    sfVector2f left_ray = (sfVector2f) {
        LID_ORI.x + cos(left_rad_ray) * LID_VIEW_DIST,
        LID_ORI.y + sin(left_rad_ray) * LID_VIEW_DIST
    };
    sfVector2f right_ray = (sfVector2f) {
        LID_ORI.x + cos(right_rad_ray) * LID_VIEW_DIST,
        LID_ORI.y + sin(right_rad_ray) * LID_VIEW_DIST
    };
    sfVertex left[] = {{.position = LID_ORI, .color = sfRed},
        {.position = left_ray, .color = sfRed}};
    sfVertex right[] = {{.position = LID_ORI, .color = sfRed},
        {.position = right_ray, .color = sfRed}};
    sfVertex top[] = {{.position = left_ray, .color = sfRed},
        {.position = right_ray, .color = sfRed}};
    sfRenderWindow_drawPrimitives(WIND, left, 2, sfLines, NULL);
    sfRenderWindow_drawPrimitives(WIND, right, 2, sfLines, NULL);
    sfRenderWindow_drawPrimitives(WIND, top, 2, sfLines, NULL);
    get_distance(programm, i);
}

void draw_every_lidar(programm_t *programm, int i)
{
    get_distance(programm, i);
}
