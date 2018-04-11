/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fl_cs.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apyltsov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/29 16:00:13 by apyltsov          #+#    #+#             */
/*   Updated: 2018/03/29 16:00:14 by apyltsov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"
#include <stdio.h>/////////////////////////////////////////////

void	flag_for_s(char *s, char c, t_flags *pf)
{
	char	*str;
	char	*t;

	if (s == NULL)
		s = "(null)";
	if (pf->flag_p == 1 && pf->prec < (int)ft_strlen(s))
	{
		str = (char *)ft_memalloc(sizeof(char) * pf->prec + 1);
		str = ft_strncpy(str, s, pf->prec);
	}
	else
		str = ft_strdup(s);
	t = str;
	if (pf->flag_w == 1)
		str = flag_wigth(str, c, pf);
	buff_add(str);
	ft_strdel(&t);
}

void	flag_wigth_c(char c, t_flags *pf)
{
	char	s[2];
	char	*str;
	int		i;

	s[0] = c;
	s[1] = 0;
	str = NULL;
	i = 0;

	if (pf->flag_w == 1 && pf->wigth > 1)
		if (s[0] == '\0')
		{

			str = (char *)ft_memalloc(pf->wigth);
			while (i < pf->wigth - 1)
				if (pf->zero == 1)
					str[i++] = '0';
				else
					str[i++] = ' ';
			g_i += ft_strlen(g_buff) + i + 1;
			ft_putstr(g_buff);
			ft_bzero(g_buff, ft_strlen(g_buff));
			write(1, str, i + 1);
			ft_strdel(&str);
		}
		else
			str = flag_wigth(s, c, pf);
	else
		if(!*s)
		{
			g_i +=  ft_strlen(g_buff) + 1;
			write(1, g_buff, g_i);
			ft_bzero(g_buff, BUFF_SIZE);
		}
		else
			str = ft_strdup(s);
	buff_add(str);
}