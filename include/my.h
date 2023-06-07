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
#include <string.h>
#include <time.h>
#include <ncurses.h>


#define PI 3.14159265

#define BORDER 50
#define CAR_BASE 180 // default orientation of the car
#define WINDOW_W 1800
#define WINDOW_H 1700
#define WINDOW_BPP 32



#define START_X 825.00
#define START_Y 1470.00

#define CAR_RATIO 0.12

#define FW_MX_SP 10

#define LIDAR_ANGLE 60
#define LID_DEMIANG LIDAR_ANGLE / 2

#define EVNT programm->windows.event
#define WIND programm->windows.window
#define VMODE programm->windows.video_mode
#define MAIN_VIEW programm->windows.my_view
#define DEBUG_TXT programm->debug_text.text
#define DEBUG_STR programm->debug_text.string
#define DEBUG_POS programm->debug_text.position
#define DEBUG_FONT programm->debug_text.font
#define SIMULATION_TXT programm->simulation_status.text
#define SIMULATION_STR programm->simulation_status.string
#define SIMULATION_POS programm->simulation_status.position
#define SIMULATION_FONT programm->simulation_status.font
#define VMODE_WD VMODE.width
#define VMODE_HT VMODE.height
#define VMODE_BPP VMODE.bitsPerPixel
#define CORE_CLK programm->core_clock.clock
#define CORE_TIME programm->core_clock.time
#define CORE_SEC programm->core_clock.seconds

#define PI_RAD PI / 180

#define WINDOW_CENTER_X WINDOW_W / 2
#define WINDOW_CENTER_Y WINDOW_H / 2
#define VIEW_ZOOM programm->windows.view_zoom
#define NEW_VIEW_X MOUSE_X - MOUSE_HOLD_X
#define NEW_VIEW_Y MOUSE_Y - MOUSE_HOLD_Y

#define FPS_VAR programm->fps_counter
#define FPS FPS_VAR.fps
#define FPS_TIME FPS_VAR.time_var.time
#define FPS_SEC FPS_VAR.time_var.seconds
#define FPS_CLK FPS_VAR.time_var.clock
#define FPS_TXT FPS_VAR.fps_counter_text.text
#define FPS_STR FPS_VAR.fps_counter_text.string
#define FPS_FONT FPS_VAR.fps_counter_text.font
#define FPS_POS FPS_VAR.fps_counter_text.position

#define CAR_COUNT programm->car_counter.car_counter_text
#define CAR_COUNT_TXT CAR_COUNT.text
#define CAR_COUNT_STR CAR_COUNT.string
#define CAR_COUNT_FONT CAR_COUNT.font
#define CAR_COUNT_POS CAR_COUNT.position

#define BG_IMG programm->background.image
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
#define BG_COL_SIZE programm->background.collision_size
#define BG_COL_WD BG_COL_SIZE.x
#define BG_COL_HT BG_COL_SIZE.y
#define BG_SP_LID programm->background.lidar_sprite
#define BG_LID_IMG programm->background.lidar
#define BG_TX_LID programm->background.lidar_texture

#define CAR_VECT ((sfVector2f){CAR_RATIO * BG_RATIO_X, CAR_RATIO * BG_RATIO_Y})

#define MAP1TXPATH "assets/map/track_one/track_one.png"
#define MAP1COLPATH "assets/map/track_one/track_one_border.png"
#define CARPATH "assets/car.png"
#define FONT "assets/arial.ttf"

#define CAR_ST programm->car
#define CAR_SP programm->car[NBCAR].sprite
#define CAR_IMG programm->car[NBCAR].image
#define CAR_TX programm->car[NBCAR].texture
#define CAR_ID programm->car[NBCAR].id
#define CAR_DEGR programm->car[NBCAR].orientation
#define CAR_CR_COMMAND programm->car[NBCAR].command
#define CAR_CR_TIME programm->car[NBCAR].alive_time
#define CAR_CR_TIME_CLK programm->car[NBCAR].alive_time.clock
#define CAR_CR_TIME_TIME programm->car[NBCAR].alive_time.time
#define CAR_CR_TIME_SEC programm->car[NBCAR].alive_time.seconds
#define CAR_CR_CDOWN programm->car[NBCAR].command_cooldown
#define CAR_CR_LIDINIT programm->car[NBCAR].lid_initialized
#define CAR_CR_CDOWN_CLK programm->car[NBCAR].command_cooldown.clock
#define CAR_CR_CDOWN_TIME programm->car[NBCAR].command_cooldown.time
#define CAR_CR_CDOWN_SEC programm->car[NBCAR].command_cooldown.seconds
#define CAR_CR_COOLTIME programm->car[NBCAR].command_cooldown_time
#define CAR_ACTUAL programm->car[NBCAR].actual
#define CAR_NBCAR programm->car[NBCAR]
#define CAR_NBCAR_POS programm->car[NBCAR].position
#define CAR_FWINIT programm->car[NBCAR].actual.car_forward
#define CAR_BCINIT programm->car[NBCAR].actual.car_forward
#define CAR_WDINIT programm->car[NBCAR].actual.car_forward
#define CAR_CWINIT programm->car[NBCAR].actual.car_forward
#define CAR_INU_LEN programm->car[NBCAR].len_entered
#define CAR_INI_SIMSTART programm->car[NBCAR].sim_started

#define CAR_INIT_LIDAR programm->car[NBCAR].lidar
#define CAR_INIT_CLOCK programm->car[NBCAR].lidar->time_var

#define CAR_NPX CAR_NEWPOS.x
#define CAR_NPY CAR_NEWPOS.y
#define CAR_NPXB WINDOW_W - BORDER
#define CAR_NPYB WINDOW_H - BORDER


#define CAR_STSP CAR_ST[i].sprite
#define CAR_POS CAR_ST[i].position
#define CAR_COMMAND CAR_ST[i].command
#define CAR_IMGI programm->car[i].image
#define CAR_NEWPOS CAR_ST[i].new_position
#define CAR_ORI CAR_ST[i].orientation
#define CAR_BCSP CAR_ST[i].actual->car_backward
#define CAR_FWSP CAR_ST[i].actual->car_forward
#define CAR_WD CAR_ST[i].actual->wheel_dir
#define CAR_CW CAR_ST[i].actual->cycle_wait
#define CAR_IACTUAL CAR_ST[i].actual
#define CAR_COMMAND_CD CAR_ST[i].command_cooldown
#define CAR_INP_LEN CAR_ST[i].len_entered
#define CAR_COMMAND_COOLTIME CAR_ST[i].command_cooldown_time
#define CAR_COMMAND_CD_CLK CAR_ST[i].command_cooldown.clock
#define CAR_COMMAND_CD_TIME CAR_ST[i].command_cooldown.time
#define CAR_COMMAND_CD_SEC CAR_ST[i].command_cooldown.seconds
#define CAR_SIMSTART CAR_ST[i].sim_started


#define CAR_LIDAR CAR_ST[i].lidar
#define CAR_LID_INIT CAR_ST[i].lid_initialized
#define CAR_LID_DEMI CAR_LIDAR->lidar_demi_ang
#define LID_DIST CAR_LIDAR->lidar_distance
#define LID_CX CAR_LIDAR->correct_x
#define LID_CY CAR_LIDAR->correct_y
#define LID_SX CAR_LIDAR->size_car_x
#define LID_SY CAR_LIDAR->size_car_y
#define LID_CO CAR_LIDAR->cos_ori
#define LID_SI CAR_LIDAR->sin_ori
#define LID_WR CAR_LIDAR->is_wall_right
#define LID_WL CAR_LIDAR->is_wall_left
#define LID_SISX CAR_LIDAR->lidsxlidsi
#define LID_COSX CAR_LIDAR->lidsxlidco
#define LID_INTERSECT CAR_LIDAR->intersection
#define LID_ORI CAR_LIDAR->lidar_origin
#define LID_VIEW_DIST CAR_LIDAR->lidar_view_distance
#define DISTCONV CAR_LIDAR->dist_convert
#define CAR_CLOCK CAR_LIDAR->time_var

#define SIMULATION programm->simulation
#define SIMULATION_PAUSED programm->simulation_paused
#define DEBUG programm->debug_state
#define MOUSE_LEFT programm->keyboard.mouse_left

#define NBCAR programm->nb_car

#define K_Z programm->keyboard.z
#define K_Q programm->keyboard.q
#define K_S programm->keyboard.s
#define K_D programm->keyboard.d
#define MOUSE_X programm->keyboard.mouse_pos.x
#define MOUSE_Y programm->keyboard.mouse_pos.y
#define MOUSE_HOLD_X programm->keyboard.holded_at.x
#define MOUSE_HOLD_Y programm->keyboard.holded_at.y



typedef struct windows_s {
    sfView* my_view;
    int view_zoom;
    sfVector2f viewSize;
    sfRenderWindow *window;
    sfVideoMode video_mode;
    sfEvent event;
} windows_t;

typedef struct time_var_s {
    sfClock *clock;
    sfTime time;
    float seconds;
} time_var_t;


typedef struct background_s {
    sfVector2f map_ratio;
    sfVector2u size;
    sfImage *image;
    sfTexture *texture;
    sfSprite *sprite;
    sfImage *collision_image;
    sfTexture *collision_texture;
    sfSprite *collision_sprite;
    sfVector2u collision_size;
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

typedef struct keyboard_s {
    bool z;
    bool q;
    bool s;
    bool d;
    bool mouse_left;
    sfVector2i mouse_pos;
    sfVector2i holded_at;
} keyboard_t;

typedef struct lidar_s {
    int *lidar_distance;
    time_var_t time_var;
    int update_time;
    sfVector2f intersection;
    float correct_x;
    float correct_y;
    float size_car_x;
    float size_car_y;
    float cos_ori;
    float sin_ori;
    float lidsxlidco;
    float lidsxlidsi;
    int lidar_view_ang;
    int lidar_demi_ang;
    float lidar_view_distance;
    float dist_convert;
    sfVector2f lidar_origin;
    bool is_wall_right;
    bool is_wall_left;
} lidar_t;

typedef struct car_s {
    sfTexture *texture;
    sfImage *image;
    sfSprite *sprite;
    lidar_t *lidar;
    car_actual_t *actual;
    sfVector2f position;
    sfVector2f new_position;
    bool lid_initialized;
    bool sim_started;
    time_var_t alive_time;
    int len_entered;
    char *command;
    time_var_t command_cooldown;
    float command_cooldown_time;
    float orientation;
    int id;
} car_t;

typedef struct text_s {
    sfVector2f position;
    sfText *text;
    char *string;
    sfFont *font;
} text_t;

typedef struct car_counter_s {
    text_t car_counter_text;
} car_counter_t;

typedef struct fps_counter_s {
    time_var_t time_var;
    text_t fps_counter_text;
    int fps;
} fps_counter_t;

typedef struct programm_s {

    bool simulation;
    bool simulation_paused;
    bool debug_state;
    text_t debug_text;
    text_t simulation_status;
    time_var_t core_clock;
    keyboard_t keyboard;
    windows_t windows;
    fps_counter_t fps_counter;
    background_t background;
    car_counter_t car_counter;
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
void prompt_usr_cmd(programm_t *programm, int i);
void keyboard_released(programm_t *programm);
void keyboard_pressed(programm_t *programm);
void mouse_moved(programm_t *programm);
void move_zqsd_car(programm_t *programm);
void handle_car_command(programm_t *programm, int i);
int round_to_int(double x);
void exec_unknown_command(void);
void exec_stop_simulation(programm_t *programm, int i);
void exec_start_simulation(programm_t *programm, int i);
void exec_get_current_wheels(programm_t *programm, int i);
void exec_get_current_speed(programm_t *programm, int i);
void exec_get_info_simtime(programm_t *programm, int i);
void exec_get_car_speed_max(programm_t *programm, int i);
void exec_get_car_speed_min(programm_t *programm, int i);
void exec_wheel_dir(programm_t *programm, int i);
void exec_car_forward(programm_t *programm, int i);
void exec_car_backwards(programm_t *programm, int i);
void exec_get_info_lidar(programm_t *programm, int i);
void sim_not_started(programm_t *programm, int i);
int my_strlen(const char *str);
int round_to_int(double x);
void get_distance(programm_t *programm, int i);
void draw_lidar(programm_t *programm, int i);
void draw_every_lidar(programm_t *programm, int i);
char *int_to_char_array(char *pretext, int i);
void create_text(programm_t *programm);
void init_car_counter(programm_t *programm);
void init_debug_mode(programm_t *programm);
void init_simu_stat_text(programm_t *programm);
void draw_infos(programm_t *programm);
void draw_number_of_car(programm_t *programm);
void update_fps(programm_t *programm);





