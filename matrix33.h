#ifndef MATRIX33_H
#define MATRIX33_H
#include "matrix.h"

void m33_init(Matrix33 *mat);
double m33_get_value(Matrix33 *mat, int row, int col);
Matrix33 m33_multiply(Matrix33 *lhs, Matrix33 *rhs);
Matrix33 m33_tilda(Matrix33 *mat);
Matrix33 m33_rot(Matrix31 k, double rads);
Matrix33 m33_rot_X(double rads);
Matrix33 m33_rot_Y(double rads);
Matrix33 m33_rot_Z(double rads);
void m33_row_multiply(Matrix33 *mat, int row, double mult);
void m33_row_subtract(Matrix33 *mat, int pos_row, int neg_row);
void m33_zero_cell(Matrix33 *mat, Matrix33 *invert, int row, int col, int base_row);
Matrix33 m33_identity();
#endif ///MATRIX33_H

//test ,added by leimingshan