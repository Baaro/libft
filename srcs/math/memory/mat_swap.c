#include "libmath.h"

void	mat_swap(t_matrix a, t_matrix b)
{
	if (a == NULL || b == NULL)
		mat_error_handle(E_MATRIX_NULL, __func__);
	else if (a == b)
		return ;

	size_t	tmp_rows;
	size_t	tmp_cols;
	t_any*	tmp_data;

	tmp_rows = a->rows;
	tmp_cols = a->cols;
	tmp_data = a->data;
	a->rows = b->rows;
	a->cols = b->cols;
	a->data = b->data;
	b->rows = tmp_rows;
	b->cols = tmp_cols;
	b->data = tmp_data;
}
