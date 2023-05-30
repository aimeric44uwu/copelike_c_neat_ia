/*
** EPITECH PROJECT, 2022
** neat_ia
** File description:
** car_command.c
*/

#include "my.h"

void handle_car_command(programm_t *programm, int i)
{
    prompt_usr_cmd(programm, i);
    CAR_COMMAND_CD_TIME = sfClock_getElapsedTime(CAR_COMMAND_CD_CLK);
    CAR_COMMAND_CD_SEC = CAR_COMMAND_CD_TIME.microseconds / 1000000.0;
    if (!DEBUG && CAR_COMMAND_CD_SEC < CAR_COMMAND_COOLTIME)
        return;
    sfClock_restart(CAR_COMMAND_CD_CLK);
    if (!CAR_LID_INIT)
        return;
    if (strcmp(CAR_COMMAND, "GET_INFO_LIDAR") == 0)
        exec_get_info_lidar(programm, i);
    CAR_COMMAND = "NULL";
}
