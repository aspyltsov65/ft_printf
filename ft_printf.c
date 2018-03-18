/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apyltsov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/22 21:18:25 by apyltsov          #+#    #+#             */
/*   Updated: 2018/02/22 21:18:27 by apyltsov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h> //////////////////////////////////////

int	ft_printf(const char *format, ...)
{
	int		i;
	int		j;
	char	*buff;
	char	*time;
	char	*line;
	t_flags	*pf;

	i = -1;
	j = 0;
	buff = ft_strnew(4096);
	while (format[++i] != '\0')
		if (format[i] == '%' && format[i + 1])
		{
			if (!(pf = (t_flags*)ft_memalloc(sizeof(t_flags))))
				return (0);
			va_start(pf->argptr, format);
			ft_parse(&format[i + 1], pf);
		}
		else
			if (j < 4096)
				buff[j++] = format[i];
			else
			{
				time = ft_strnew(4096);
				line = buff;
				buff = ft_strjoin(buff, time);
				ft_strdel(&time);
				ft_strdel(&line);
			}
	va_end(pf->argptr);
	ft_putstr(buff);
	return (1);
}
