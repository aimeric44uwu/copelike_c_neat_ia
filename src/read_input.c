/*
** EPITECH PROJECT, 2022
** neat_ia
** File description:
** read_input.c
*/

#include "my.h"
#include <ncurses.h>


void prompt_usr_cmd(programm_t *programm, int i)
{
    initscr();
    timeout(0);
    noecho();
    int len = 0;
    int c = getch();
    endwin();
    if (c != -1) {
        char *res = malloc(sizeof(char) * 100);
        while (c != '\n') {
            res[len] = c;
            len++;
            c = getch();
        }
        res[len] = '\0';
        CAR_COMMAND = strdup(res);
    }
}
