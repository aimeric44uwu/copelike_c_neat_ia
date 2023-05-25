/*
** EPITECH PROJECT, 2022
** neat_ia
** File description:
** check_for_wall.c
*/

#include "my.h"

static int round_to_int(float num)
{
    int result = (int) num;

    if (num - result >= 0.5) {
        result++;
    }
    return result;
}

static bool wall_top(programm_t *programm, int i)
{
    float tr_x = LID_CX + (LID_SX * LID_CO);
    float tr_y = LID_CY + (LID_SX * LID_SI);
    float tr_x_r = tr_x - (LID_SY * LID_SI);
    float tr_y_r = tr_y + (LID_SY * LID_CO);
    if (DEBUG)
        sfImage_setPixel(BG_LID_IMG, tr_x, tr_y, sfWhite);
    if (DEBUG)
        sfImage_setPixel(BG_LID_IMG, tr_x_r, tr_y_r, sfWhite);
    if (sfImage_getPixel(BG_COL_IMG, tr_x, tr_y).a == 255)
        return true;
    if (sfImage_getPixel(BG_COL_IMG, tr_x_r, tr_y_r).a == 255)
        return true;
    return false;
}

bool wall_bottom(programm_t *programm, int i)
{
    float tr_x = LID_CX - (LID_SY * LID_SI);
    float tr_y = LID_CY + (LID_SY * LID_CO);
    if (DEBUG)
        sfImage_setPixel(BG_LID_IMG, tr_x, tr_y, sfWhite);
    if (DEBUG)
        sfImage_setPixel(BG_LID_IMG, LID_CX, LID_CY, sfWhite);
    if (sfImage_getPixel(BG_COL_IMG, tr_x, tr_y).a == 255)
        return true;
    if (sfImage_getPixel(BG_COL_IMG, LID_CX, LID_CY).a == 255)
        return true;
    return false;
}

bool check_for_walls(programm_t *programm, int i)
{
    LID_CX = round_to_int(CAR_NPX / BG_RATIO_X);
    LID_CY = round_to_int(CAR_NPY / BG_RATIO_Y);
    LID_CO = cos((PI / 180) * CAR_ORI);
    LID_SI = sin((PI / 180) * CAR_ORI);
    if (wall_top(programm, i))
        return true;
    if (wall_bottom(programm, i))
        return true;
    return false;
}
