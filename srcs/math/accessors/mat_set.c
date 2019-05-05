#include "libmath.h"

t_any	mat_set(t_matrix a, size_t i, size_t j, t_any x)
{
	if (a == NULL)
		mat_error_handle(E_MATRIX_NULL, __func__);
	else if (i == 0 || j == 0)
		mat_error_handle(E_IDX_ZERO, __func__);
	a->data[i * j] = x;
	return (x);
}
