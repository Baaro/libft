/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsokolog <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/07 20:49:39 by vsokolog          #+#    #+#             */
/*   Updated: 2018/02/09 00:26:54 by vsokolog         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/libft.h"

static int		ft_check(char **str, char *bf, char **line, int ret)
{
	char	*del;
	char	*pos;

	if (*str == NULL)
		return (0);
	pos = NULL;
	del = *str;
	(*str = ft_strjoin(*str, bf)) ? ft_strdel(&del) : 0;
	ft_strclr(bf);
	if ((pos = ft_strchr(*str, '\n')))
	{
		*line = ft_strsub(*str, 0, pos - (*str));
		del = *str;
		(*str = ft_strdup(pos + 1)) ? ft_strdel(&del) : 0;
		ft_strdel(&bf);
		return (1);
	}
	if (ret == 0 && *str[0] != '\0')
	{
		(*line = ft_strdup(*str)) ? ft_strdel(&bf) : 0;
		ft_strdel(str);
		return (1);
	}
	return (0);
}

int				get_next_line(const int fd, char **line)
{
	static char		*str;
	char			*bf;
	int				ret;

	if (fd < 0 || !line || read(fd, NULL, 0) < 0 || BUFF_SIZE_GNL < 1)
		return (-1);
	if (str == NULL)
		str = ft_strnew(0);
	bf = ft_strnew(BUFF_SIZE_GNL);
	while (1)
	{
		if (str && !ft_strchr(str, '\n'))
		{
			ret = read(fd, bf, BUFF_SIZE_GNL);
			bf[ret] = '\0';
		}
		if (!str || (ret == 0 && (str)[0] == '\0'))
			break ;
		if (ret == -1)
			break ;
		if (str && ft_check(&str, bf, line, ret))
			return (1);
	}
	ft_strdel(&bf);
	return (ret == -1 ? -1 : 0);
}
