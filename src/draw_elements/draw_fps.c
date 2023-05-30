/*
** EPITECH PROJECT, 2022
** neat_ia
** File description:
** draw_fps.c
*/

#include "my.h"

void reverse_string(char* pretext, int j, char *result)
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

void update_fps(programm_t *programm)
{
    FPS++;
    FPS_TIME = sfClock_getElapsedTime(FPS_CLK);
    FPS_SEC = FPS_TIME.microseconds / 1000000.0;
    if (FPS_SEC > 1) {
        FPS_STR = int_to_char_array("fps: ", FPS);
        sfText_setString(FPS_TXT, FPS_STR);
        sfClock_restart(FPS_CLK);
        FPS = 0;
    }
    sfRenderWindow_drawText(WIND, FPS_TXT, NULL);
}
