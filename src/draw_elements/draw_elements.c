/*
** EPITECH PROJECT, 2022
** neat_ia
** File description:
** draw_element.c
*/

#include "my.h"

void draw_number_of_car(programm_t *programm)
{
    CAR_COUNT_STR = malloc(sizeof(char) * 200);
    CAR_COUNT_STR = int_to_char_array("nb car: ", NBCAR);
    sfText_setString(CAR_COUNT_TXT, CAR_COUNT_STR);
    sfRenderWindow_drawText(WIND, CAR_COUNT_TXT, NULL);
    free(CAR_COUNT_STR);
}

void draw_background(programm_t *programm)
{
    sfRenderWindow_drawSprite(WIND, BG_SP, NULL);
    sfRenderWindow_drawSprite(WIND, BG_COL_SP, NULL);
    sfRenderWindow_drawSprite(WIND, BG_SP_LID, NULL);
}

void draw_cars(programm_t *programm)
{
    for (int i = 0; i < NBCAR; i++) {
        sfRenderWindow_drawSprite(WIND, CAR_STSP, NULL);
        LID_ORI = (sfVector2f){(CAR_POS.x + LID_CO) -
        (LID_COSX * (LID_SX / 10)) - (LID_CO * (LID_SX / 2)) -
        (LID_SI * (LID_SX / 3)) + (LID_CO * DISTCONV) ,

        ( CAR_POS.y + LID_SI) - (LID_SISX * (LID_SX / 10)) +
        (LID_CO * (LID_SY / 1.3)) - (LID_SI * (LID_SX / 2)) +
        (LID_SI * DISTCONV)};
        CAR_CLOCK.time = sfClock_getElapsedTime(CAR_CLOCK.clock);
        CAR_CLOCK.seconds = CAR_CLOCK.time.microseconds / 1000000.0;
        if (!DEBUG && CAR_CLOCK.seconds < CAR_LIDAR->update_time)
            return;
        sfClock_restart(CAR_CLOCK.clock);
        if (DEBUG)
            draw_every_lidar(programm, i);
        else
            draw_lidar(programm, i);
    }
}
