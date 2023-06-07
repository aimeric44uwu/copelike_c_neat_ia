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
    if (!SIMULATION)
        return;
    if (!CAR_LID_INIT)
        return;
    if (!CAR_SIMSTART)
        return sim_not_started(programm, i);
    if (strcmp(CAR_COMMAND, "GET_INFO_LIDAR") == 0)
        exec_get_info_lidar(programm, i);
    else if (strncmp(CAR_COMMAND, "CAR_FORWARD", 11) == 0)
        exec_car_forward(programm, i);
    else if (strncmp(CAR_COMMAND, "CAR_BACKWARDS", 13) == 0)
        exec_car_backwards(programm, i);
    else if (strncmp(CAR_COMMAND, "WHEELS_DIR", 10) == 0)
        exec_wheel_dir(programm, i);
    else if (strstr(CAR_COMMAND, "GET_CAR_SPEED_MIN") == 0)
        exec_get_car_speed_min(programm, i);
    else if (strstr(CAR_COMMAND, "GET_CAR_SPEED_MAX") == 0)
        exec_get_car_speed_max(programm, i);
    else if (strstr(CAR_COMMAND, "GET_INFO_SIMTIME") == 0)
        exec_get_info_simtime(programm, i);
    else if (strstr(CAR_COMMAND, "GET_CURRENT_SPEED") == 0)
        exec_get_current_speed(programm, i);
    else if (strstr(CAR_COMMAND, "GET_CURRENT_WHEELS") == 0)
        exec_get_current_wheels(programm, i);
    else if (strcmp(CAR_COMMAND, "START_SIMULATION") == 0)
        exec_start_simulation(programm, i);
    else if (strcmp(CAR_COMMAND, "STOP_SIMULATION") == 0)
        exec_stop_simulation(programm, i);
    else 
        exec_unknown_command();
    CAR_COMMAND = "NULL";
}
