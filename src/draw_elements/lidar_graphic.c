/*
** EPITECH PROJECT, 2022
** neat_ia
** File description:
** lidar_graphic.c
*/

#include "my.h"

static void draw_intersection(programm_t *programm,
int i, sfVector2f intersection)
{
    for (int x = -5; x < 5; x++)
        for (int y = -5; y < 5; y++)
            sfImage_setPixel(BG_LID_IMG, intersection.x + x,
                intersection.y + y, sfRed);
}

static void find_an_intersection(programm_t *programm, int i, int angle)
{
    sfVector2f pixel_size = {BG_COL_WD, BG_COL_HT};
    float angrad = (CAR_ORI + angle) * PI_RAD;
    for (int t = 0; t <= LID_VIEW_DIST; t += 10) {
        sfVector2f sample = {(LID_ORI.x + t * cos(angrad)) / BG_RATIO_X,
            (LID_ORI.y + t * sin(angrad)) / BG_RATIO_Y};
        if (sample.x < 0 || sample.x >= pixel_size.x ||
            sample.y < 0 || sample.y >= pixel_size.y)
            break;
        if (DEBUG)
            sfImage_setPixel(BG_LID_IMG, sample.x, sample.y, sfYellow);
        if (sfImage_getPixel(BG_COL_IMG, sample.x, sample.y).a == 255) {
            LID_INTERSECT = sample;
            break;
        }
    }
}

static void foreach_angle(programm_t *programm, int i, int angle)
{
    LID_INTERSECT = (sfVector2f) {0.0, 0.0};
    find_an_intersection(programm, i, angle);
    if (LID_INTERSECT.x == 0.0 || LID_INTERSECT.y == 0.0)
        return;
    if (DEBUG)
        draw_intersection(programm, i, LID_INTERSECT);
    if (CAR_CLOCK.seconds > CAR_LIDAR->update_time) {
        float distance = sqrtf(((LID_ORI.x - (LID_INTERSECT.x * BG_RATIO_X))
        * (LID_ORI.x - (LID_INTERSECT.x * BG_RATIO_X))) +
        ((LID_ORI.y - (LID_INTERSECT.y * BG_RATIO_Y)) *
        (LID_ORI.y - (LID_INTERSECT.y * BG_RATIO_Y))));
        if (distance > 500)
            distance = 500;
        LID_DIST[angle + 30] = round_to_int((distance / 500) * 3050);
        sfClock_restart(CAR_CLOCK.clock);
    }
}

void get_distance(programm_t *programm, int i)
{
    CAR_CLOCK.time = sfClock_getElapsedTime(CAR_CLOCK.clock);
    CAR_CLOCK.seconds = CAR_CLOCK.time.microseconds / 1000000.0;
    if (!DEBUG && CAR_CLOCK.seconds < CAR_LIDAR->update_time)
        return;
    for (int angle = -30; angle < 31; angle += 1) {
        foreach_angle(programm, i, angle);
    }
    sfTexture_updateFromImage(BG_TX_LID, BG_LID_IMG, 0, 0);
}
