/*
** EPITECH PROJECT, 2022
** neat_ia
** File description:
** utils.c
*/

#include "my.h"

bool is_outside_border(programm_t *programm, int i)
{
    if (CAR_NPX < BORDER || CAR_NPX > CAR_NPXB ||
    CAR_NPY < BORDER || CAR_NPY > CAR_NPYB)
        return true;
    return false;
}

void my_putstr(char *str)
{
    int i = 0;
    while (str[i] != '\0') {
        write(1, &str[i], 1);
        i++;
    }
}

void my_putchar(char c)
{
    write(1, &c, 1);
}

void my_put_nbr(int nb)
{
    int number = 1;
    if (nb < 0) {
        my_putchar('-');
        nb *= -1;
    }
    while ((nb / number) >= 10)
        number = number * 10;
    while (number > 0) {
        my_putchar((nb / number) % 10 + '0');
        number /= 10;
    }
}

float my_abs(float num)
{
    if (num < 0)
        return num * -1;
    return num;
}
