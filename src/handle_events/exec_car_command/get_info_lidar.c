/*
** EPITECH PROJECT, 2022
** neat_ia
** File description:
** get_info_lidar.c
*/

#include "my.h"

void exec_get_info_lidar(programm_t *programm, int i)
{
    for (int a = 0; a < 60; a++)
        printf("%d:", LID_DIST[a]);
    printf("%d\n", LID_DIST[60]);
}
