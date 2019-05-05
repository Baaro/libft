#include "libmath.h"

t_matrix	mat_create_nxm(size_t rows, size_t cols)
{
	if (rows == 0 || cols == 0)
		mat_error_handle(E_IDX_ZERO, __func__);

	t_matrix	m;

	m = ft_memalloc(sizeof(t_matrixdesc));
	m->rows = rows;
	m->cols = cols;
	m->data = ft_memalloc(rows * cols);
	return (m);
}
