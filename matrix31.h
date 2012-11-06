#ifndef MATRIX31_H
#define MATRIX31_H
#include "matrix.h"

double m31_get_value(Matrix31 *mat, int row);
double m31_and(Matrix31 *lhs, Matrix31 *rhs);
Matrix31 m31_multiply(Matrix33 *lhs, Matrix31 *rhs);
//double m31_get_X(Matrix31 *mat);
//void m31_set_X(Matrix31 *mat, double val);
//double m31_get_Y(Matrix31 *mat);
//void m31_set_Y(Matrix31 *mat, double val);
//double m31_get_Z(Matrix31 *mat);
//void m31_set_Z(Matrix31 *mat, double val);
Matrix31 m31_Y_vector();
Matrix31 m31_Z_vector();
#endif  ///MATRIX31_H
