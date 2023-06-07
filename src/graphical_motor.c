/*
** EPITECH PROJECT, 2022
** neat_ia
** File description:
** graphical_motor.c
*/

#include "my.h"

void main_loop(programm_t *programm)
{
    create_car(programm);
    while (sfRenderWindow_isOpen(WIND)) {
        CORE_TIME = sfClock_getElapsedTime(CORE_CLK);
        CORE_SEC = CORE_TIME.microseconds / 1000000.0;
        if (CORE_SEC < 0.001)
            continue;
        sfClock_restart(CORE_CLK);
        while (sfRenderWindow_pollEvent(WIND, &EVNT))
            event_handler(programm);
        sfRenderWindow_clear(WIND, sfBlack);
        draw_background(programm);
        move_car(programm);
        draw_cars(programm);
        update_fps(programm);
        draw_number_of_car(programm);
        draw_infos(programm);
        sfRenderWindow_setView(WIND, programm->windows.my_view);
        sfRenderWindow_display(WIND);
    }
}

int main(void)
{
    programm_t *programm = malloc(sizeof(programm_t));

    if (!programm)
        error_malloc();
    init_all(programm);
    main_loop(programm);
    return 0;
}
