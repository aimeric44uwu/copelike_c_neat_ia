/*
** EPITECH PROJECT, 2022
** neat_ia
** File description:
** car_backward.c
*/

#include "my.h"

static float get_float_from_last_colon(char *input_string) {
    char *last_colon = strrchr(input_string, ':');

    if (last_colon == NULL)
        return -99.9f;
    char *last_colon_index = last_colon + 1;
    return atof(last_colon_index);
}

void exec_car_backwards(programm_t *programm, int i)
{
    float result = get_float_from_last_colon(CAR_COMMAND);
    if (result == -99.9f) {
        printf("error invalid speed\n");
        return;
    }
    if (result >= -1 && result <= 1)
        CAR_BCSP = result;
}
