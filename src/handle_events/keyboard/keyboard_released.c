/*
** EPITECH PROJECT, 2022
** neat_ia
** File description:
** keyboard_released.c
*/

#include "my.h"

void keyboard_released(programm_t *programm)
{
    int i = 0;
    if (EVNT.key.code == sfKeyZ) {
        CAR_FWSP = 0;
        K_Z = false;
    }
    if (EVNT.key.code == sfKeyQ || EVNT.key.code == sfKeyD) {
        CAR_WD = 0;
        K_Q = false;
        K_D = false;
    }
    if (EVNT.key.code == sfKeyS) {
        CAR_BCSP = 0;
        K_S = false;
    }
}
