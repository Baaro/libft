#include "matrix.h"

size_t	mat_cols(const t_matrix a)
{
	if (a == NULL)
		mat_error_handle(E_MATRIX_NULL, __func__);
	return (a->cols);
}