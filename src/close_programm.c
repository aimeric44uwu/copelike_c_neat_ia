/*
** EPITECH PROJECT, 2022
** neat_ia
** File description:
** close_programm.c
*/

#include "my.h"

int close_program(programm_t *programm)
{
    my_putstr("closing program\n");
    for (int i = 0; i < NBCAR; i++) {
        free(CAR_IACTUAL);
        free(CAR_LIDAR);
    }
    sfSprite_destroy(BG_SP);
    sfTexture_destroy(BG_TX);
    sfSprite_destroy(BG_COL_SP);
    sfTexture_destroy(BG_COL_TX);
    sfImage_destroy(BG_COL_IMG);
    sfRenderWindow_close(WIND);
    sfRenderWindow_destroy(WIND);
    free(programm->car);
    free(programm);
    endwin();
    nocbreak();
    my_putstr("programm closed without error\n");
    exit(0);
    return 0;
}
