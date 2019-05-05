#include "matrix.h"

static t_any	mat_row_by_col(t_matrix a, t_matrix b, size_t i)
{
	t_any x;
	size_t j;

	j = 0;
	while (++j <= mat_cols(a))
		x += mat_get(a, i, j) * mat_get(b, i, j);
	return (x);
}

void	mat_mul_mat(t_matrix a, t_matrix b, t_matrix c)
{
	if (a == NULL || b == NULL || c == NULL)
		mat_error_handle(E_MATRIX_NULL, __func__);
	else if (mat_cols(b) != mat_rows(c))
		mat_error_handle(E_MATRIX_NOTEQ, __func__);
	
	mat_resize(a, mat_rows(b), mat_cols(c));

	size_t	i;
	size_t	j;

	i = 0;
	while (++i <= mat_rows(a))
	{
		j = 0;
		while (++j <= mat_cols(a))
			mat_set(a, i, j, mat_row_by_col(b, c, i));
	}
}
