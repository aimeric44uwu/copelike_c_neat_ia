/*
** EPITECH PROJECT, 2022
** neat_ia
** File description:
** my.h
*/

#pragma once

#include <SFML/Audio.h>
#include <SFML/Graphics.h>
#include <SFML/Window.h>
#include <SFML/System.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <stdbool.h>
#include <math.h>

#define PI 3.14159265

#define BORDER 50
#define CAR_BASE 180
#define WINDOW_W 1800
#define WINDOW_H 1700
#define WINDOW_BPP 32

#define DEBUG 1

#define START_X 825.00
#define START_Y 1470.00

#define CAR_RATIO 0.13


#define EVNT programm->windows.event
#define WIND programm->windows.window
#define VMODE programm->windows.video_mode
#define VMODE_WD VMODE.width
#define VMODE_HT VMODE.height
#define VMODE_BPP VMODE.bitsPerPixel

#define BG_SP programm->background.sprite
#define BG_TX programm->background.texture
#define BG_RATIO programm->background.map_ratio
#define BG_RATIO_X BG_RATIO.x
#define BG_RATIO_Y BG_RATIO.y
#define BG_SIZE programm->background.size
#define BG_WD programm->background.size.x
#define BG_HT programm->background.size.y
#define PIXEL_PTR programm->background.pixels
#define BG_COL_SP programm->background.collision_sprite
#define BG_COL_TX programm->background.collision_texture
#define BG_COL_IMG programm->background.collision_image
#define BG_SP_LID programm->background.lidar_sprite
#define BG_LID_IMG programm->background.lidar
#define BG_TX_LID programm->background.lidar_texture

#define CAR_VECT ((sfVector2f){CAR_RATIO * BG_RATIO_X, CAR_RATIO * BG_RATIO_Y})

#define MAP1TXPATH "assets/map/track_one/track_one.png"
#define MAP1COLPATH "assets/map/track_one/track_one_border.png"
#define CARPATH "assets/car.png"

#define CAR_ST programm->car
#define CAR_SP programm->car[NBCAR].sprite
#define CAR_IMG programm->car[NBCAR].image
#define CAR_TX programm->car[NBCAR].texture
#define CAR_ID programm->car[NBCAR].id
#define CAR_DEGR programm->car[NBCAR].orientation
#define CAR_ACTUAL programm->car[NBCAR].actual
#define CAR_NBCAR programm->car[NBCAR]
#define CAR_NBCAR_POS programm->car[NBCAR].position
#define CAR_FWINIT programm->car[NBCAR].actual.car_forward
#define CAR_BCINIT programm->car[NBCAR].actual.car_forward
#define CAR_WDINIT programm->car[NBCAR].actual.car_forward
#define CAR_CWINIT programm->car[NBCAR].actual.car_forward
#define CAR_INIT_LIDAR programm->car[NBCAR].lidar

#define CAR_NPX CAR_NEWPOS.x
#define CAR_NPY CAR_NEWPOS.y
#define CAR_NPXB WINDOW_W - BORDER
#define CAR_NPYB WINDOW_H - BORDER


#define CAR_STSP CAR_ST[i].sprite
#define CAR_POS CAR_ST[i].position
#define CAR_IMGI programm->car[i].image
#define CAR_NEWPOS CAR_ST[i].new_position
#define CAR_ORI CAR_ST[i].orientation
#define CAR_BCSP CAR_ST[i].actual->car_backward
#define CAR_FWSP CAR_ST[i].actual->car_forward
#define CAR_WD CAR_ST[i].actual->wheel_dir
#define CAR_CW CAR_ST[i].actual->cycle_wait
#define CAR_IACTUAL CAR_ST[i].actual

#define CAR_LIDAR CAR_ST[i].lidar
#define LID_CX CAR_LIDAR->correct_x
#define LID_CY CAR_LIDAR->correct_y
#define LID_SX CAR_LIDAR->size_car_x
#define LID_SY CAR_LIDAR->size_car_y
#define LID_CO CAR_LIDAR->cos_ori
#define LID_SI CAR_LIDAR->sin_ori

#define START_SIMULATION programm->start_simulation
#define STOP_SIMULATION programm->stop_simulation

#define NBCAR programm->nb_car

typedef struct windows_s {
    sfRenderWindow *window;
    sfVideoMode video_mode;
    sfEvent event;
} windows_t;

typedef struct background_s {
    sfVector2f map_ratio;
    sfVector2u size;
    sfTexture *texture;
    sfSprite *sprite;
    sfImage *collision_image;
    sfTexture *collision_texture;
    sfSprite *collision_sprite;
    sfImage *lidar;
    sfTexture *lidar_texture;
    sfSprite *lidar_sprite;
} background_t;

typedef struct car_actual_s {
    float car_forward;
    float car_backward;
    float wheel_dir;
    int cycle_wait;
} car_actual_t;

typedef struct lidar_s {
    float correct_x;
    float correct_y;
    float size_car_x;
    float size_car_y;
    float cos_ori;
    float sin_ori;
} lidar_t;

typedef struct car_s {
    sfTexture *texture;
    sfImage *image;
    sfSprite *sprite;
    lidar_t *lidar;
    car_actual_t *actual;
    sfVector2f position;
    sfVector2f new_position;
    float orientation;
    int id;
} car_t;

typedef struct programm_s {
    bool start_simulation;
    bool stop_simulation;
    windows_t windows;
    background_t background;
    car_t *car;
    int nb_car;

} programm_t;


void my_putstr(char *str);
void my_put_nbr(int nb);
bool check_for_walls(programm_t *programm, int i);
int close_program(programm_t *programm);
void create_car(programm_t *programm);
void draw_background(programm_t *programm);
void draw_cars(programm_t *programm);
void error_malloc(void);
void error_creating_element(void);
void main_loop(programm_t *programm);
void event_handler(programm_t *programm);
void move_car(programm_t *programm);
void init_all(programm_t *programm);
void my_puterror(char *str);
void print_mouse_pos(programm_t *programm);
bool is_outside_border(programm_t *programm, int i);
float my_abs(float num);
void my_putchar(char c);
