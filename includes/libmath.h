#ifndef LIBMATH_H
# define LIBMATH_H

# include <stdlib.h>

/* Matrix */
typedef double      t_any;

typedef struct		s_matrixdesc
{
	size_t			rows;
	size_t			cols;
	t_any*			m;
}					t_matrixdesc;

typedef t_matrixdesc* t_matrix;

/** Memory management **/
t_matrix			ft_mat_create(size_t rows, size_t cols);
void				ft_mat_resize(t_matrix a, size_t rows, size_t cols);
void				ft_mat_swap(t_matrix a, t_matrix b); 
void				ft_mat_free(t_matrix a);

/** Accessors **/
t_any				ft_mat_get(const t_matrix a, size_t i, size_t j);
t_any				ft_mat_set(t_matrix m, size_t i, size_t j, t_any x);

size_t				ft_mat_rows(const t_matrix a);
size_t				ft_mat_cols(const t_matrix a);

/** Operations **/
void				ft_mat_mul(t_matrix a, t_matrix b, t_matrix c);
void				ft_mat_add(t_matrix a, t_matrix b, t_matrix c);

#endif