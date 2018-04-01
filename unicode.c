/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unicode.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apyltsov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/30 18:13:25 by apyltsov          #+#    #+#             */
/*   Updated: 2018/03/30 18:13:30 by apyltsov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
// #include <stdio.h>
// #include <locale.h>//////////////////////////////////

void	unicode_lc(int c, t_flags *pf)
{
	char	*s;

	s = NULL;
	create_unicode(c, &s);
	apply_flags(s, 'C', pf);
}


void	create_unicode(int c, char **str)
{
	char	s[5];

	ft_bzero(s, 5);
	if (c <= 0x7F)
		s[0] = (char)c;
	else if (c <= 0x7FF)
	{
		s[0] = (char)(c >> 6 | 0xC0);
		s[1] = (char)((c & 0x3F) | 0x80);
	}
	else if (c <= 0xFFFF)
	{
		s[0] = (char)(c >> 12 | 0xE0);
		s[1] = (char)(((c >> 6) & 0x3F) | 0x80);
		s[2] = (char)((c & 0x3F) | 0x80);
	}
	else if (c <= 0x1FFFFF)
	{
		s[0] = (char)((c >> 18) | 0xF0);
		s[1] = (char)(((c >> 12) & 0x3F) | 0x80);
		s[2] = (char)(((c >> 6) & 0x3F) | 0x80);
		s[3] = (char)((c & 0x3F) | 0x80);
	}
	my_join(str, s);
}

void	my_join(char **str, char *s)
{
	char	*time;

	time = *str;
	*str = ft_strjoin(*str, s);
	if (time)
		ft_strdel(&time);
}
void	unicode_ls(int *str, t_flags *pf)
{
	int		i;
	char	*s;

	i = -1;
	while (str[++i])
		create_unicode(str[i], &s);
	apply_flags(s, 'S', pf);
}










