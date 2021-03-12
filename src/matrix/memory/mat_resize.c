#include "matrix.h"

void	mat_resize(t_matrix a, size_t rows, size_t cols)
{
	if (a == NULL)
		mat_error_handle(E_MATRIX_NULL, __func__);
	else if (rows == 0 || cols == 0)
		mat_error_handle(E_IDX_ZERO, __func__);	

	a->rows = rows;
	a->cols = cols;
	ft_memdel((void **)&a->data);
	a->data = ft_memalloc(rows * cols);
}
