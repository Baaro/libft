#include "matrix.h"

void	mat_mul_scalar(t_matrix a, t_any scalar)
{
	if (a == NULL)
		mat_error_handle(E_MATRIX_NULL, __func__);
	size_t i;
	size_t j;

	i = 0;
	while (++i <= mat_rows(a))
	{
		j = 0;
		while (++j <= mat_cols(a))
			mat_set(a, i, j, mat_get(a, i, j) * scalar);
	}
}
