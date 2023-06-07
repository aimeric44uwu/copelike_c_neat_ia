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

int my_strlen(const char *str)
{
    int len = 0;

    while (*str++)
        ++len;
    return len;
}

int round_to_int(double x)
{
    int result;

    if (x >= 0)
        result = (int)(x + 0.5);
    else
        result = (int)(x - 0.5);
    return result;
}

static void reverse_string(char* pretext, int j, char *result)
{
    int k = my_strlen(pretext);
    int len = j + k;

    for (k; k < len / 2 ; k++) {
        char temp = result[k];
        result[k] = result[len - k - 1];
        result[len - k - 1] = temp;
    }
}

char *int_to_char_array(char *pretext, int i)
{
    int j = 0;
    int number = i;
    char *resultcpy = NULL;
    int pretext_len = my_strlen(pretext);
    char *result = malloc(sizeof(char) * (pretext_len + 200));

    for (int k = 0; k < pretext_len; k++)
        result[j++] = pretext[k];
    while (number > 0) {
        int lastDigit = number % 10;
        number = number / 10;
        result[j++] = lastDigit + '0';
    }
    reverse_string(pretext, j, result);
    result[j++] = '\0';
    resultcpy = strdup(result);
    free(result);
    return resultcpy;
}