#ifndef MATRIX_H
# define MATRIX_H

# include <math.h>
# include "libft.h"

/* Matrix */

/** Matrix errors types **/
typedef enum		e_mat_error
{
	E_MATRIX_NULL = 1,
	E_MATRIX_NOTEQ,
	E_IDX_ZERO,
}					t_mat_error;

typedef int64_t		t_any;

typedef struct		s_matrixdesc
{
	size_t			rows;
	size_t			cols;
	t_any*			data;
}					t_matrixdesc;

typedef t_matrixdesc* t_matrix;

/** Memory management **/
void				mat_create_nxm(t_matrix *m, size_t rows, size_t cols);
t_matrix			mat_create_4x4(void);

void				mat_resize(t_matrix a, size_t rows, size_t cols);
void				mat_swap(t_matrix a, t_matrix b);
void				mat_free(t_matrix *a);

/** Accessors **/
t_any				mat_get(const t_matrix a, size_t i, size_t j);
t_any				mat_set(t_matrix a, size_t i, size_t j, t_any x);

size_t				mat_rows(const t_matrix a);
size_t				mat_cols(const t_matrix a);

/** Operations **/
void				mat_mul_mat(t_matrix a, t_matrix b, t_matrix c); /* a = b + c */
void				mat_mul_scalar(t_matrix a, t_any x);
void				mat_add(t_matrix a, t_matrix b, t_matrix c); /* a = b + c */

/** Matrix errors handler **/
void				mat_error_handle(const t_mat_error me, const char *func);

#endif
