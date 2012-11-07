#include "angles.h"
#ifndef M_PI
#define M_PI       3.14159265358979323846  /* pi */
#endif // !M_PI


double degree2radian(double degree)
{
	return ((degree * M_PI) / 180.0);
}

double radian2degree(double radian)
{
	return ((radian * 180.0) / M_PI);
}
