/*
** EPITECH PROJECT, 2022
** neat_ia
** File description:
** error_occured.c
*/

#include "my.h"

void error_malloc(void)
{
    my_puterror("Error: malloc failed\n");
    exit(84);
}

void error_creating_element(void)
{
    my_puterror("Error: creating element failed\n");
    exit(84);
}
