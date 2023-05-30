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
    CAR_INIT_LIDAR->size_car_x = (sfImage_getSize(CAR_IMG).x * CAR_RATIO);
    CAR_INIT_LIDAR->size_car_y = (sfImage_getSize(CAR_IMG).y * CAR_RATIO);
    CAR_INIT_LIDAR->lidar_view_distance = 1500;
    CAR_INIT_LIDAR->lidar_view_ang = 60;
    CAR_INIT_LIDAR->lidar_demi_ang = CAR_INIT_LIDAR->lidar_view_ang / 2;
    CAR_INIT_LIDAR->lidar_distance = malloc(sizeof(int) * 62);
    for (int i = 0; i < 62; i++)
        CAR_INIT_LIDAR->lidar_distance[i] = 0;
    CAR_INIT_LIDAR->dist_convert = CAR_INIT_LIDAR->lidar_view_distance * 0.15;
}

static void create_clock(programm_t *programm)
{
    CAR_INIT_CLOCK.clock = sfClock_create();
    CAR_INIT_CLOCK.time = sfClock_getElapsedTime(CAR_INIT_CLOCK.clock);
    CAR_INIT_CLOCK.seconds = 0.0;
    CAR_INIT_LIDAR->update_time = 0.1;
}

static void create_spec(programm_t *programm)
{
    CAR_ACTUAL = malloc(sizeof(car_t));
    CAR_ACTUAL->car_forward = 0.5;
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
    create_clock(programm);
    NBCAR++;
}
