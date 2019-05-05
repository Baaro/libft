#include "matrix.h"

void	mat_add(t_matrix a, t_matrix b, t_matrix c)
{
	if (a == NULL || b == NULL || c == NULL)
		mat_error_handle(E_MATRIX_NULL, __func__);
	else if (mat_rows(b) != mat_rows(c) ||
		mat_cols(b) != mat_cols(c))
		mat_error_handle(E_MATRIX_NOTEQ, __func__);
	mat_resize(a, mat_rows(b), mat_cols(b));

	size_t	i;
	size_t	j;

	i = 0;
	while (++i <= mat_rows(a))
	{
		j = 0;
		while (++j <= mat_cols(a))
			mat_set(a, i, j, mat_get(b, i, j) + mat_get(c, i, j));
	}
}