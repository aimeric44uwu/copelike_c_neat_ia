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
        while (sfRenderWindow_pollEvent(WIND, &EVNT)) {
            event_handler(programm);
        }
        sfRenderWindow_clear(WIND, sfBlack);
        draw_background(programm);
        move_car(programm);
        draw_cars(programm);
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
