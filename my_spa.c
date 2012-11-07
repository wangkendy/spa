#include "my_spa.h"

void spa_init(spa_data *spa)
{
	tzset(); // set timezone
	long tz = (-timezone) / 3600;
	spa->timezone      = tz;
	spa->delta_t       = 80;
	//spa.longitude     = 116.358;
	//spa.latitude      = 39.974;
	//spa.elevation     = 100;
	//spa.pressure      = 1015;
	//spa.temperature   = 11;
	spa->slope         = 0;//30;
	spa->azm_rotation  = 0;//-10;
	spa->atmos_refract = 0.5667;
	spa->function      = SPA_ALL;
}

void set_atmosphere(spa_data *spa, double barometric_pressure_mbar, double temperature_c)
{
	spa->pressure = barometric_pressure_mbar;
	spa->temperature = temperature_c;
}

void set_location(spa_data *spa, double longitude, double latitude, double elevation)
{
	spa->longitude = longitude;
	spa->latitude = latitude;
	spa->elevation = elevation;
}

int calculate_position(spa_data *spa, struct tm *t)
{
	int result;
	spa->year          = t->tm_year + 1900;
	spa->month         = t->tm_mon + 1;
	spa->day           = t->tm_mday;
	spa->hour          = t->tm_hour;
	spa->minute        = t->tm_min;
	spa->second        = t->tm_sec;
	result = spa_calculate(spa);
	return result;
}

struct tm get_sun_rise(spa_data* spa)
{
	struct tm t;
	double min, sec;
	min = 60.0*(spa->sunrise - (int)(spa->sunrise));
	sec = 60.0*(min - (int)min);
	t.tm_year = spa->year - 1900;
	t.tm_mon = spa->month - 1;
	t.tm_mday = spa->day;
	t.tm_hour = (int)(spa->sunrise);
	t.tm_min = (int)min;
	t.tm_sec = (int)sec;
	return t;
}

struct tm get_sun_set(spa_data* spa)
{
	struct tm t;
	double min, sec;
	min = 60.0*(spa->sunset- (int)(spa->sunset));
	sec = 60.0*(min - (int)min);
	t.tm_year = spa->year - 1900;
	t.tm_mon = spa->month - 1;
	t.tm_mday = spa->day;
	t.tm_hour = (int)(spa->sunset);
	t.tm_min = (int)min;
	t.tm_sec = (int)sec;
	return t;
}

struct tm get_sun_transit(spa_data* spa)
{
	struct tm t;
	double min, sec;
	min = 60.0*(spa->suntransit- (int)(spa->suntransit));
	sec = 60.0*(min - (int)min);
	t.tm_year = spa->year - 1900;
	t.tm_mon = spa->month - 1;
	t.tm_mday = spa->day;
	t.tm_hour = (int)(spa->suntransit);
	t.tm_min = (int)min;
	t.tm_sec = (int)sec;
	return t;
}

double get_azimuth_angle(spa_data* spa)
{
	return spa->azimuth;
}

double get_elevation_angle(spa_data* spa)
{
	return spa->zenith;
}
