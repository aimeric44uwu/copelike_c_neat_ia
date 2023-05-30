/*
** EPITECH PROJECT, 2022
** neat_ia
** File description:
** init_text_element.c
*/

#include "my.h"

void create_text(programm_t *programm)
{
    FPS_FONT = sfFont_createFromFile(FONT);
    FPS_TXT = sfText_create();
    FPS_POS = (sfVector2f){100, 50};
    FPS_STR = "fps: 0";
    sfText_setString(FPS_TXT, FPS_STR);
    sfText_setFont(FPS_TXT, FPS_FONT);
    sfText_setCharacterSize(FPS_TXT, 50);
    sfText_setPosition(FPS_TXT, FPS_POS);
    sfText_setColor(FPS_TXT, sfBlack);
}

void init_car_counter(programm_t *programm)
{
    CAR_COUNT_FONT = sfFont_createFromFile(FONT);
    CAR_COUNT_TXT = sfText_create();
    CAR_COUNT_POS = (sfVector2f){400, 50};
    CAR_COUNT_STR = "nb of car : 0";
    sfText_setString(CAR_COUNT_TXT, CAR_COUNT_STR);
    sfText_setFont(CAR_COUNT_TXT, CAR_COUNT_FONT);
    sfText_setCharacterSize(CAR_COUNT_TXT, 50);
    sfText_setPosition(CAR_COUNT_TXT, CAR_COUNT_POS);
    sfText_setColor(CAR_COUNT_TXT, sfBlack);
}
