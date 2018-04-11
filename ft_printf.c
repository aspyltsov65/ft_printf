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
	t_flags	*pf;
	va_list	argptr;

	i = -1;
	g_i = 0;
	g_buff = (char *)ft_memalloc(sizeof(char) * BUFF_SIZE);
	if (!(pf = (t_flags*)ft_memalloc(sizeof(t_flags))))
		return (0);
	va_start(argptr, format);
	while (format[++i] != '\0')
		if (format[i] == '%' && format[i + 1])
		{
			i += ft_parse(&format[i + 1], pf, argptr);
			ft_bzero(pf, sizeof(t_flags));
		}
		else if (format[i] != '%')
			if (ft_strlen(g_buff) + 1 < BUFF_SIZE)
				g_buff[ft_strlen(g_buff)] = format[i];
			else
			{
				ft_putstr(g_buff);
				g_i += ft_strlen(g_buff);
				ft_bzero(g_buff, BUFF_SIZE);
				g_buff[ft_strlen(g_buff)] = format[i];
			}
		else
			break;
	va_end(argptr);
	ft_putstr(g_buff);
	g_i += ft_strlen(g_buff);
	ft_strdel(&g_buff);
	// while(1)
	// 	;
	return (g_i);
}


