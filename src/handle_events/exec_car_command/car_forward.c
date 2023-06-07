/*
** EPITECH PROJECT, 2022
** neat_ia
** File description:
** car_forward.c
*/

#include "my.h"

static float get_float_from_last_colon(char *input_string) {
    char *last_colon = strrchr(input_string, ':');

    if (last_colon == NULL)
        return -99.9f;
    char *last_colon_index = last_colon + 1;
    return atof(last_colon_index);
}

void exec_car_forward(programm_t *programm, int i)
{
    printf("car forward called with function %s\n", CAR_COMMAND);
    float result = get_float_from_last_colon(CAR_COMMAND);
    if (result == -99.9f) {
        printf("error invalid speed\n");
        return;
    }
    printf("new car forward is %f\n", result);
    if (result >= -1 && result <= 1)
        CAR_FWSP = result;
}
//CAR_FORWARD:0.3