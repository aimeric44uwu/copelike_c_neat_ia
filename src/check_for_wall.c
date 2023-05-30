/*
** EPITECH PROJECT, 2022
** neat_ia
** File description:
** check_for_wall.c
*/

#include "my.h"

static bool wall_right(programm_t *programm, int i)
{
    float tr_x = LID_CX - (LID_SY * LID_SI);
    float tr_y = LID_CY + (LID_SY * LID_CO);
    float tr_x_r = tr_x + LID_COSX;
    float tr_y_r = tr_y + LID_SISX;
    if (DEBUG) {
        sfImage_setPixel(BG_LID_IMG, tr_x, tr_y, sfWhite);
        sfImage_setPixel(BG_LID_IMG, tr_x_r, tr_y_r, sfWhite);
    }
    if (sfImage_getPixel(BG_COL_IMG, tr_x, tr_y).a)
        return true;
    if (sfImage_getPixel(BG_COL_IMG, tr_x_r, tr_y_r).a)
        return true;
    return false;
}

static bool wall_left(programm_t *programm, int i)
{
    float tr_x = LID_CX + LID_COSX;
    float tr_y = LID_CY + LID_SISX;
    if (DEBUG) {
        sfImage_setPixel(BG_LID_IMG, tr_x, tr_y, sfWhite);
        sfImage_setPixel(BG_LID_IMG, LID_CX, LID_CY, sfWhite);
    }
    if (sfImage_getPixel(BG_COL_IMG, tr_x, tr_y).a)
        return true;
    if (sfImage_getPixel(BG_COL_IMG, LID_CX, LID_CY).a )
        return true;
    return false;
}

bool check_for_walls(programm_t *programm, int i)
{
    LID_CX = round_to_int(CAR_NPX / BG_RATIO_X);
    LID_CY = round_to_int(CAR_NPY / BG_RATIO_Y);
    LID_CO = cos((PI / 180) * CAR_ORI);
    LID_SI = sin((PI / 180) * CAR_ORI);
    LID_COSX = LID_SX * LID_CO;
    LID_SISX = LID_SX * LID_SI;
    LID_WR = wall_right(programm, i);
    LID_WL = wall_left(programm, i);
    if (LID_WR || LID_WL)
        return true;
    return false;
}
