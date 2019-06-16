#include "matrix.h"

void	mat_create_nxm(t_matrix *m, size_t rows, size_t cols)
{
	if (rows == 0 || cols == 0)
		mat_error_handle(E_IDX_ZERO, __func__);

	*m = ft_memalloc(sizeof(t_matrixdesc));
	(*m)->rows = rows;
	(*m)->cols = cols;
	(*m)->data = (t_any *)ft_memalloc(rows * cols);
}
