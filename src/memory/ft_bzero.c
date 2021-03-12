/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsokolog <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/06 16:58:47 by vsokolog          #+#    #+#             */
/*   Updated: 2018/02/17 19:42:57 by vsokolog         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/libft.h"

void	ft_bzero(void *s, size_t nbyte)
{
	size_t j;

	j = 0;
	while (j < nbyte)
		((char *)s)[j++] = '\0';
}
