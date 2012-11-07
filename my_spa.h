#ifndef MY_SPA_H
#define MY_SPA_H
#include "spa.h"
#include <time.h>

void spa_init(spa_data *spa);
//void calculate_sunrise_sunset(spa_data *spa);
struct tm get_sun_rise(spa_data* spa);
struct tm get_sun_set(spa_data* spa);
struct tm get_sun_transit(spa_data* spa);
int calculate_position(spa_data *spa, struct tm *t);
void set_atmosphere(spa_data *spa, double barometric_pressure_mbar, double temperature_c);
void set_location(spa_data *spa, double longitude, double latitude, double elevation);
double get_azimuth_angle(spa_data *spa);
double get_elevation_angle(spa_data *spa);

#endif // MY_SPA_H
