/*
** EPITECH PROJECT, 2022
** neat_ia
** File description:
** create_car.c
*/

#include "my.h"

static void init_lidar(programm_t *programm)
{
    CAR_INIT_LIDAR = malloc(sizeof(lidar_t));
    CAR_INIT_LIDAR->size_car_x = (sfImage_getSize(CAR_IMG).x * 0.13);
    CAR_INIT_LIDAR->size_car_y = (sfImage_getSize(CAR_IMG).y * 0.13);
}

static void create_spec(programm_t *programm)
{
    CAR_ACTUAL = malloc(sizeof(car_t));
    CAR_ACTUAL->car_forward = 0.4;
    CAR_ACTUAL->car_backward = 0.0;
    CAR_ACTUAL->wheel_dir = 0.0;
    CAR_ACTUAL->cycle_wait = 0;
}

void create_car(programm_t *programm)
{
    CAR_ST = realloc(CAR_ST, sizeof(car_t) * (NBCAR + 1));
    CAR_IMG = sfImage_createFromFile(CARPATH);
    CAR_TX = sfTexture_createFromImage(CAR_IMG, NULL);
    CAR_SP = sfSprite_create();
    CAR_ID = NBCAR;
    CAR_DEGR = CAR_BASE;
    CAR_NBCAR_POS = (sfVector2f){START_X, START_Y};
    create_spec(programm);
    sfSprite_setRotation(CAR_SP, CAR_DEGR);
    sfSprite_setTexture(CAR_SP, CAR_TX, sfTrue);
    sfSprite_setPosition(CAR_SP, CAR_NBCAR_POS);
    sfSprite_setScale(CAR_SP, CAR_VECT);
    sfSprite_setColor(CAR_SP, (sfColor){255, 255, 255, 255});
    init_lidar(programm);
    NBCAR++;
}
