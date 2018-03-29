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
#include "libprintf.h"
#include <stdio.h>/////////////////////////////////////////////

void	flag_for_s(char *s, char c, t_flags *pf)
{
	int		i;
	char	*str;

	str = s;
	if (s == NULL)
	{
		s = (char *)ft_memalloc(sizeof(char) * 7);
		s = "(null)";
	}
	if (c == 's' && pf->flag_p == 1 && pf->prec < ft_strlen(s))
	{
		str = (char *)ft_memalloc(sizeof(char) * pf->prec);
		str = ft_strncpy(str, s, pf->prec);
		printf("string %s\n", str);
	}
	if (pf->flag_w == 1)
		str = flag_wigth(str, c, pf);
	buff_add(str);
}

void	flag_wigth_c(char c, t_flags *pf)
{
	char	*s;
	char	*str;

	if (pf->flag_w == 1 && pf->wigth > 1)
	{
		if(!(s = (char *)ft_memalloc(pf->wigth + 1)))
			return ;
		s[0] = c;
		str = flag_wigth(s, c, pf);
		buff_add(str);
	}
}