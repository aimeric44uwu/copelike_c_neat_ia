/*
** EPITECH PROJECT, 2022
** neat_ia
** File description:
** keyboard_pressed.c
*/

#include "my.h"

static void reduce_zoom(programm_t *programm)
{
    VIEW_ZOOM -= 10;
    sfView_setSize(MAIN_VIEW,
    (sfVector2f){(WINDOW_W) - (VIEW_ZOOM),
    (WINDOW_H) - (VIEW_ZOOM)});
}

static void increase_zoom(programm_t *programm)
{
    VIEW_ZOOM += 10;
    sfView_setSize(MAIN_VIEW,
    (sfVector2f){(WINDOW_W) - (VIEW_ZOOM),
    (WINDOW_H) - (VIEW_ZOOM)});
}

static void keyboard_pressed_ptwo(programm_t *programm)
{
    switch (EVNT.key.code) {
        case sfKeyA:
            create_car(programm);
            break;
        case sfKeyR:
            DEBUG = !DEBUG;
            break;
        case sfKeyP:
            reduce_zoom(programm);
            break;
        case sfKeyM:
            increase_zoom(programm);
            break;
    }
}

void keyboard_pressed(programm_t *programm)
{
    int keypressed = EVNT.key.code;

    if (keypressed == sfKeyZ || keypressed == sfKeyS || keypressed == sfKeyQ
        || keypressed == sfKeyD) {
            if (keypressed == sfKeyZ)
                K_Z = true;
            if (keypressed == sfKeyS)
                K_S = true;
            if (keypressed == sfKeyQ)
                K_Q = true;
            if (keypressed == sfKeyD)
                K_D = true;
    } else if (EVNT.key.code == sfKeyEscape)
        close_program(programm);
    else
        keyboard_pressed_ptwo(programm);
}
