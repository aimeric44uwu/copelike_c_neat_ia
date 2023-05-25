/*
** EPITECH PROJECT, 2022
** neat_ia
** File description:
** init.c
*/

#include "my.h"

static void create_windows(programm_t *programm)
{
    VMODE_WD = WINDOW_W;
    VMODE_HT = WINDOW_H;
    VMODE_BPP = WINDOW_BPP;
    WIND = sfRenderWindow_create(VMODE, "Neat IA", sfDefaultStyle, NULL);
    sfRenderWindow_setFramerateLimit(WIND, 60);
    NBCAR = 0;
    START_SIMULATION = true;
    STOP_SIMULATION = false;
    BG_RATIO = (sfVector2f){1.5, 1.5};

    if (!WIND)
        error_creating_element();
}

static void init_background(programm_t *programm)
{
    BG_TX = sfTexture_createFromFile(MAP1TXPATH, NULL);
    BG_SP = sfSprite_create();
    BG_COL_IMG = sfImage_createFromFile(MAP1COLPATH);
    BG_COL_TX = sfTexture_createFromImage(BG_COL_IMG, NULL);
    BG_COL_IMG = sfImage_createFromFile(MAP1COLPATH);
    BG_COL_SP = sfSprite_create();
    BG_SIZE = sfTexture_getSize(BG_TX);
    BG_LID_IMG = sfImage_createFromColor(BG_SIZE.x, BG_SIZE.y, sfTransparent);
    BG_SP_LID = sfSprite_create();
    BG_TX_LID = sfTexture_createFromImage(BG_LID_IMG, NULL);
}

static void create_background(programm_t *programm)
{
    init_background(programm);
    if (!BG_TX || !BG_SP || !BG_COL_TX || !BG_COL_SP)
        return error_creating_element();
    sfSprite_setTexture(BG_COL_SP, BG_COL_TX, sfTrue);
    sfSprite_setTexture(BG_SP_LID, BG_TX_LID, sfTrue);
    sfSprite_setOrigin(BG_SP_LID, (sfVector2f){0, 0});
    sfSprite_setScale(BG_SP_LID, BG_RATIO);
    sfSprite_setColor(BG_COL_SP, (sfColor){255, 255, 255, 0});
    sfSprite_setOrigin(BG_COL_SP, (sfVector2f){0, 0});
    sfSprite_setScale(BG_COL_SP, BG_RATIO);
    sfSprite_setTexture(BG_SP, BG_TX, sfTrue);
    sfSprite_setColor(BG_SP, (sfColor){255, 255, 255, 255});
    sfSprite_setOrigin(BG_SP, (sfVector2f){0, 2});
    sfSprite_setScale(BG_SP, BG_RATIO);
}

void init_all(programm_t *programm)
{
    create_windows(programm);
    create_background(programm);
}
