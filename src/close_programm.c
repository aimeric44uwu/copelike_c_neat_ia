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
        sfImage_destroy(CAR_IMGI);
        sfTexture_destroy(programm->car[i].texture);
        sfSprite_destroy(programm->car[i].sprite);
        sfClock_destroy(programm->car[i].lidar->time_var.clock);
        sfClock_destroy(programm->car[i].command_cooldown.clock);
        sfClock_destroy(programm->car[i].alive_time.clock);

        free(CAR_IACTUAL);
        free(CAR_LIDAR->lidar_distance);
        free(CAR_LIDAR);
    }
    free(programm->car);
    sfImage_destroy(BG_IMG);
    sfTexture_destroy(BG_TX);
    sfSprite_destroy(BG_SP);
    sfImage_destroy(BG_COL_IMG);
    sfTexture_destroy(BG_COL_TX);
    sfSprite_destroy(BG_COL_SP);
    sfImage_destroy(BG_LID_IMG);

    sfSprite_destroy(BG_SP_LID);
    sfTexture_destroy(BG_TX_LID);
    sfClock_destroy(FPS_CLK);
    sfClock_destroy(CORE_CLK);
    sfView_destroy(MAIN_VIEW);
    sfText_destroy(SIMULATION_TXT);
    sfFont_destroy(SIMULATION_FONT);
    sfText_destroy(DEBUG_TXT);
    sfFont_destroy(DEBUG_FONT);
    sfText_destroy(CAR_COUNT_TXT);
    sfFont_destroy(CAR_COUNT_FONT);
    sfText_destroy(FPS_TXT);
    sfFont_destroy(FPS_FONT);
    sfRenderWindow_close(WIND);
    sfRenderWindow_destroy(WIND);
    free(programm);
    endwin();
    refresh();
    nocbreak();
    my_putstr("programm closed without error\n");
    exit(0);
    return 0;
}
