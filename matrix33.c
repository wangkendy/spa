#include "matrix33.h"
#include "matrix31.h"
#include <math.h>
#include <stdio.h>

void m33_init(Matrix33 *mat)
{
	int i, j;
	for(i = 0; i < 3; i++)
		for(j = 0; j < 3; j++)
			mat->val[i][j] = 0.0;
}

double m33_get_value(Matrix33 *mat, int row, int col)
{
	return mat->val[row][col];
}

Matrix33 m33_multiply(Matrix33 *lhs, Matrix33 *rhs)
{
	Matrix33 mat;
	int i, j, k;
	double temp;
	for(i = 0; i < 3; i++) {
		for(j = 0; j < 3; j++) {
			temp = 0.0;
			for(k = 0; k < 3; k++) {
				temp += lhs->val[i][k] * rhs->val[k][j];
			}
			mat.val[i][j] = temp;
		}
	}
	return mat;
}

Matrix33 m33_tilda(Matrix33 *op0)
{
//	Matrix33 m = new Matrix33();
//	Matrix33 op = new Matrix33(op0);
//	m.val[0, 0] = 1.0;
//	m.val[1, 1] = 1.0;
//	m.val[2, 2] = 1.0;
//	double x = 1.0 / op.val[0, 0];
//	op.Row_Multiply(0, x);
//	m.Row_Multiply(0, x);
//	op.zero_cell(m, 1, 0, 0);
//	op.zero_cell(m, 2, 0, 0);
//	x = 1.0 / op.val[1, 1];
//	op.Row_Multiply(1, x);
//	m.Row_Multiply(1, x);
//	op.zero_cell(m, 2, 1, 1);
//	x = 1.0 / op.val[2, 2];
//	op.Row_Multiply(2, x);
//	m.Row_Multiply(2, x);
//	op.zero_cell(m, 1, 2, 2);
//	op.zero_cell(m, 0, 2, 2);
//	x = 1.0 / op.val[1, 1];
//	op.Row_Multiply(1, x);
//	m.Row_Multiply(1, x);
//	op.zero_cell(m, 0, 1, 1);
//	x = 1.0 / op.val[0, 0];
//	op.Row_Multiply(0, x);
//	m.Row_Multiply(0, x);
//	return m;

	Matrix33 m;
	Matrix33 op = *op0;
	double x;
	m33_init(&m);
	m.val[0][0] = 1.0;
	m.val[1][1] = 1.0;
	m.val[2][2] = 1.0;

	x = 1.0 / op.val[0][0];
	m33_row_multiply(&op, 0, x);
	m33_row_multiply(&m, 0, x);
	m33_zero_cell(&op, &m, 1, 0, 0);
	m33_zero_cell(&op, &m, 2, 0, 0);
	x = 1.0 / op.val[1][1];
	m33_row_multiply(&op, 1, x);
	m33_row_multiply(&m, 1, x);
	m33_zero_cell(&op, &m, 2, 1, 1);
	x = 1.0 / op.val[2][2];
	m33_row_multiply(&op, 2, x);
	m33_row_multiply(&m, 2, x);
	m33_zero_cell(&op, &m, 1, 2, 2);
	m33_zero_cell(&op, &m, 0, 2, 2);
	x = 1.0 / op.val[1][1];
	m33_row_multiply(&op, 1, x);
	m33_row_multiply(&m, 1, x);
	m33_zero_cell(&op, &m, 0, 1, 1);
	x = 1.0 / op.val[0][0];
	m33_row_multiply(&op, 0, x);
	m33_row_multiply(&m, 0, x);

	return m;
}

Matrix33 m33_rot(Matrix31 k, double rads)
{
	Matrix33 m;
	double vers = 1.0 - cos(rads);
//	m.val[0, 0]=((k.X * k.X) * vers) + Math.Cos(Rads);
//	m.val[1, 0]=((k.X * k.Y) * vers) + (k.Z * Math.Sin(Rads));
//	m.val[2, 0]=((k.X * k.Z) * vers) - (k.Y * Math.Sin(Rads));
//	m.val[0, 1]=((k.Y * k.X) * vers) - (k.Z * Math.Sin(Rads));
//	m.val[1, 1]=((k.Y * k.Y) * vers) + Math.Cos(Rads);
//	m.val[2, 1]=((k.Y * k.Z) * vers) + (k.X * Math.Sin(Rads));
//	m.val[0, 2]=((k.Z * k.X) * vers) + (k.Y * Math.Sin(Rads));
//	m.val[1, 2]=((k.Z * k.Y) * vers) - (k.X * Math.Sin(Rads));
//	m.val[2, 2]=((k.Z * k.Z) * vers) + Math.Cos(Rads);

	m.val[0][0]=((k.X * k.X) * vers) + cos(rads);
	m.val[1][0]=((k.X * k.Y) * vers) + (k.Z * sin(rads));
	m.val[2][0]=((k.X * k.Z) * vers) - (k.Y * sin(rads));
	m.val[0][1]=((k.Y * k.X) * vers) - (k.Z * sin(rads));
	m.val[1][1]=((k.Y * k.Y) * vers) + cos(rads);
	m.val[2][1]=((k.Y * k.Z) * vers) + (k.X * sin(rads));
	m.val[0][2]=((k.Z * k.X) * vers) + (k.Y * sin(rads));
	m.val[1][2]=((k.Z * k.Y) * vers) - (k.X * sin(rads));
	m.val[2][2]=((k.Z * k.Z) * vers) + cos(rads);
	return m;
}

Matrix33 m33_rot_X(double rads)
{
	Matrix33 m;
	m33_init(&m);
//	m.val[0, 0] = 1.0;
//	m.val[1, 1] = Math.Cos(Rads);
//	m.val[2, 2] = m.val[1, 1];
//	m.val[2, 1] = Math.Sin(Rads);
//	m.val[1, 2] = -m.val[2, 1];

	m.val[0][0] = 1.0;
	m.val[1][1] = cos(rads);
	m.val[2][2] = m.val[1][1];
	m.val[2][1] = sin(rads);
	m.val[1][2] = -m.val[2][1];

	return m;
}

Matrix33 m33_rot_Y(double rads)
{
	Matrix33 m;
	m33_init(&m);
//	m.val[0, 0] = Math.Cos(Rads);
//	m.val[0, 2] = Math.Sin(Rads);
//	m.val[1, 1] = 1.0;
//	m.val[2, 0] = -m.val[0, 2];
//	m.val[2, 2] = m.val[0, 0];

	m.val[0][0] = cos(rads);
	m.val[0][2] = sin(rads);
	m.val[1][1] = 1.0;
	m.val[2][0] = -m.val[0][2];
	m.val[2][2] = m.val[0][0];
	return m;
}

Matrix33 m33_rot_Z(double rads)
{
	Matrix33 m;
	m33_init(&m);
//	m.val[0, 0] = Math.Cos(Rads);
//	m.val[0, 1] = -Math.Sin(Rads);
//	m.val[1, 0] = -m.val[0, 1];
//	m.val[1, 1] = m.val[0, 0];
//	m.val[2, 2] = 1.0;
	m.val[0][0] = cos(rads);
	m.val[0][1] = -sin(rads);
	m.val[1][0] = -m.val[0][1];
	m.val[1][1] = m.val[0][0];
	m.val[2][2] = 1.0;
	return m;
}

void m33_row_multiply(Matrix33 *mat, int row, double mult)
{
	int i;
	for(i = 0; i < 3; i++)
		mat->val[row][i] *= mult;
}

void m33_row_subtract(Matrix33 *mat, int pos_row, int neg_row)
{
	int i;
	for(i = 0; i < 3; i++)
		mat->val[pos_row][i] -= mat->val[neg_row][i];
}

void m33_zero_cell(Matrix33 *mat, Matrix33 *invert, int row, int col, int base_row)
{
//	if (this.val[row, col] != 0.0)
//	{
//		double x = 1.0 / this.val[row, col];
//		this.Row_Multiply(row, x);
//		invert.Row_Multiply(row, x);
//		this.Row_Subtract(row, base_row);
//		invert.Row_Subtract(row, base_row);
//	}
	double x = 0;
	if(mat->val[row][col] != 0.0) {
		x = 1.0 / mat->val[row][col];
		m33_row_multiply(mat, row, x);
		m33_row_multiply(invert, row, x);
		m33_row_subtract(mat, row, base_row);
		m33_row_subtract(invert, row, base_row);
	}
}

Matrix33 m33_identity()
{
	Matrix33 id;
	m33_init(&id);
	id.val[0][0] = 1.0;
	id.val[1][1] = 1.0;
	id.val[2][2] = 1.0;
	return id;
}

void m33_print(Matrix33 *mat)
{
	int i, j;
	for(i = 0; i < 3; i++) {
		for(j = 0; j < 3; j++)
			printf("%d ", mat->val[i][j]);
		printf("\n");
	}
}
