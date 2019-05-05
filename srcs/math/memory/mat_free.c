#include "libmath.h"

void	mat_free(t_matrix* a)
{
	if (a == NULL)
		mat_error_handle(E_MATRIX_NULL, __func__);

	(*a)->cols = 0;
	(*a)->rows = 0;
	ft_memdel((void **)&(*a)->data);
	ft_memdel((void **)&(*a));
}
