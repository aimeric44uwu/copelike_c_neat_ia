/*
** EPITECH PROJECT, 2022
** neat_ia
** File description:
** event.c
*/

#include "my.h"

void move_car(programm_t *programm)
{
    if (!SIMULATION)
        return;
    sfImage_destroy(BG_LID_IMG);
    BG_LID_IMG = sfImage_createFromColor(BG_SIZE.x, BG_SIZE.y, sfTransparent);
    for (int i = 0; i < NBCAR; i++) {
        CAR_NEWPOS = CAR_POS;
        float speed = (CAR_FWSP - (CAR_BCSP / 2)) * FW_MX_SP;
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
    move_zqsd_car(programm);
}

void event_handler(programm_t *programm)
{
    if (EVNT.type == sfEvtClosed)
        close_program(programm);
    if (EVNT.type == sfEvtMouseMoved && MOUSE_LEFT)
        mouse_moved(programm);
    if (EVNT.type == sfEvtMouseButtonPressed) {
        MOUSE_HOLD_X = sfMouse_getPositionRenderWindow(WIND).x;
        MOUSE_HOLD_Y = sfMouse_getPositionRenderWindow(WIND).y;
        MOUSE_LEFT = !MOUSE_LEFT;
    }
    if (EVNT.type == sfEvtMouseButtonReleased)
        MOUSE_LEFT = !MOUSE_LEFT;
    if (EVNT.type == sfEvtKeyPressed)
        keyboard_pressed(programm);
    if (EVNT.type == sfEvtKeyReleased)
        keyboard_released(programm);
}
// sfCircleShape* point = sfCircleShape_create();
// sfCircleShape_setRadius(point, 10);
// sfColor colorunder = sfImage_getPixel(BG_IMG, LID_CX, LID_CY);
// sfCircleShape_setFillColor(point, colorunder);
// sfCircleShape_setPosition(point, (sfVector2f) { CAR_POS.x, CAR_POS.y });
// sfRenderWindow_drawCircleShape(WIND, point, NULL);
// sfCircleShape_destroy(point);
