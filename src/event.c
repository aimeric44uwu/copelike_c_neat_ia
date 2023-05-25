/*
** EPITECH PROJECT, 2022
** neat_ia
** File description:
** event.c
*/

#include "my.h"

static int round_to_int(float num)
{
    int result = (int) num;

    if (num - result >= 0.5) {
        result++;
    }
    return result;
}

void move_car(programm_t *programm)
{
    if (!START_SIMULATION)
        return;
    sfImage_destroy(BG_LID_IMG);
    BG_LID_IMG = sfImage_createFromColor(BG_SIZE.x, BG_SIZE.y, sfTransparent);
    for (int i = 0; i < NBCAR; i++) {
        CAR_NEWPOS = CAR_POS;
        float speed = CAR_FWSP - (CAR_BCSP / 2);
        CAR_NPY += (sin((PI / 180) * CAR_ORI) * speed);
        CAR_NPX += (cos((PI / 180) * CAR_ORI) * speed);
        if (check_for_walls(programm, i) || is_outside_border(programm, i))
            CAR_NEWPOS = CAR_POS;
        CAR_ORI += (CAR_WD * (speed / 2));
        if (CAR_ORI > 360)
            CAR_ORI -= 360;
        sfSprite_setPosition(CAR_STSP, CAR_NEWPOS);
        sfSprite_setRotation(CAR_STSP, round_to_int(CAR_ORI));
        CAR_POS = CAR_NEWPOS;
    }
    sfTexture_updateFromImage(BG_TX_LID, BG_LID_IMG, 0, 0);
}

static void keyboard_pressed(programm_t *programm)
{
    switch (EVNT.key.code) {
        case sfKeyA:
            create_car(programm);
            break;
        case sfKeyQ:
            programm->car[0].actual->wheel_dir -= 0.3;
            break;
        case sfKeyD:
            programm->car[0].actual->wheel_dir += 0.3;
            break;
        case sfKeyZ:
            programm->car[0].actual->car_forward += 0.1;
            programm->car[0].actual->car_backward = 0;
            break;
        case sfKeyS:
            programm->car[0].actual->car_backward += 0.1;
            programm->car[0].actual->car_forward = 0;
            break;
    }
}

void event_handler(programm_t *programm)
{
    if (EVNT.type == sfEvtClosed)
        close_program(programm);
    if (EVNT.type == sfEvtMouseButtonPressed)
        print_mouse_pos(programm);
    if (EVNT.type == sfEvtKeyPressed)
        keyboard_pressed(programm);
    if (EVNT.type == sfEvtKeyReleased)
        programm->car[0].actual->wheel_dir = 0;
}
