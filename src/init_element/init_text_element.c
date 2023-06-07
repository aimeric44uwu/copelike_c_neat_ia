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

void init_debug_mode(programm_t *programm)
{
    DEBUG_FONT = sfFont_createFromFile(FONT);
    DEBUG_TXT = sfText_create();
    DEBUG_POS = (sfVector2f){1100, 50};
    DEBUG_STR = "debug mode : on";
    sfText_setString(DEBUG_TXT, DEBUG_STR);
    sfText_setFont(DEBUG_TXT, DEBUG_FONT);
    sfText_setCharacterSize(DEBUG_TXT, 50);
    sfText_setPosition(DEBUG_TXT, DEBUG_POS);
    sfText_setColor(DEBUG_TXT, sfBlack);
}

void init_simu_stat_text(programm_t *programm)
{
    SIMULATION_FONT = sfFont_createFromFile(FONT);
    SIMULATION_TXT = sfText_create();
    SIMULATION_POS = (sfVector2f){700, 50};
    SIMULATION_STR = "simulation : off";
    sfText_setString(SIMULATION_TXT, SIMULATION_STR);
    sfText_setFont(SIMULATION_TXT, SIMULATION_FONT);
    sfText_setCharacterSize(SIMULATION_TXT, 50);
    sfText_setPosition(SIMULATION_TXT, SIMULATION_POS);
    sfText_setColor(SIMULATION_TXT, sfBlack);
}
