#include "matrix31.h"
#include "matrix33.h"

double m31_get_value(Matrix31 *mat, int row)
{
	if(row == 0)
		return mat->X;
	if(row == 1)
		return mat->Y;
	if(row == 2)
		return mat->Z;
}

double m31_and(Matrix31 *lhs, Matrix31 *rhs)
{
	return ((lhs->X * rhs->X) +
			(lhs->Y * rhs->Y) +
			(lhs->Z * rhs->Z));
}

Matrix31 m31_multiply(Matrix33 *lhs, Matrix31 *rhs)
{
	Matrix31 p;
	int x;
	double temp;
	for(x = 0; x < 3; x++) {
		temp = 0.0;
		temp += lhs->val[x][0] * rhs->X;
		temp += lhs->val[x][1] * rhs->Y;
		temp += lhs->val[x][2] * rhs->Z;
		if(x == 0)
			p.X = temp;
		else if(x == 1)
			p.Y = temp;
		else if(x == 2)
			p.Z = temp;
	}

	return p;
}

Matrix31 m31_Y_vector()
{
	Matrix31 v;
	v.X = 0.0;
	v.Y = 1.0;
	v.Z = 0.0;
	return v;
}

//Matrix31 m31_Z_vector()
//{
//	Matrix31 v;
//	v.X = 0.0;
//	v.Y = 0.0;
//	v.Z = 1.0;
//	return v;
//}
