#include "matrix.h"

void	mat_error_handle(const t_mat_error me, const char *func)
{
	if (me == E_MATRIX_NULL)
		ft_printf("The NULL Matrix found as an argument in (%s).\n", func);
	else if (me == E_MATRIX_NOTEQ)
		ft_printf("Rows and cols of matrices are not equal. Func: (%s).\n", func);
	else if (me == E_IDX_ZERO)
		ft_printf("The Zero Index found as an argument in (%s).\n", func);
	exit (EXIT_FAILURE);
}
