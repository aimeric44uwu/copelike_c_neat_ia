/*
** EPITECH PROJECT, 2022
** neat_ia
** File description:
** utils_2.c
*/

#include "my.h"

void print_mouse_pos(programm_t *programm)
{
    my_putstr("x: ");
    my_put_nbr(EVNT.mouseButton.x);
    my_putstr(" y: ");
    my_put_nbr(EVNT.mouseButton.y);
}

void my_puterror(char *str)
{
    int i = 0;
    while (str[i] != '\0') {
        write(2, &str[i], 1);
        i++;
    }
}
