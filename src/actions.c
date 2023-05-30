/*
** EPITECH PROJECT, 2022
** neat_ia
** File description:
** actions.c
*/

#include "my.h"

void move_zqsd_car(programm_t *programm)
{
    int i = 0;

    if (K_Q && CAR_WD > -1 && !LID_WL && CAR_FWSP > 0)
        CAR_WD -= 0.3;
    if (K_D && CAR_WD < 1 && !LID_WR && CAR_FWSP > 0)
        CAR_WD += 0.3;
    if (K_Q && CAR_WD > -1 && !LID_WR && CAR_BCSP > 0)
        CAR_WD -= 0.3;
    if (K_D && CAR_WD < 1 && !LID_WL && CAR_BCSP > 0)
        CAR_WD += 0.3;
    if (K_Z && CAR_FWSP < 1)
        CAR_FWSP += 0.1;
    if (K_S && CAR_BCSP < 1)
        CAR_BCSP += 0.1;
    if (CAR_FWSP > 0 && ((LID_WL && CAR_WD < 0) || (LID_WR && CAR_WD > 0)))
        CAR_WD = 0;
    if (CAR_BCSP > 0 && ((LID_WL && CAR_WD > 0) || (LID_WR && CAR_WD < 0)))
        CAR_WD = 0;
}
