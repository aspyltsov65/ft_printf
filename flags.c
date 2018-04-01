/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flags.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apyltsov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/08 20:55:50 by apyltsov          #+#    #+#             */
/*   Updated: 2018/03/08 20:55:52 by apyltsov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
// #include <stdio.h> ///////////////////////////////////

void	apply_flags(char *s, char c, t_flags *pf)
{
	int		size;
	int		i;

	size = 0;
	if (pf->flag_p == 1)
		s = flag_prec(s, pf);
	if (pf->hash == 1)
		s = flag_hash(s, c);
	if (pf->plus == 1 || pf->space == 1)
		s = flag_plus_space(s, pf);
	if (pf->flag_w == 1)
		s = flag_wigth(s, c, pf);
	i = 0;

	buff_add(s);
}

void	buff_add(char *s)
{
	int	j;

	j = ft_strlen(g_buff);
	if (j + ft_strlen(s) < BUFF_SIZE)
		ft_strcpy(g_buff + j, s);
	else
	{
		ft_putstr(g_buff);
		ft_bzero(g_buff, BUFF_SIZE);
		g_buff = ft_strcpy(g_buff, s);
	}
}

char	*ft_strtoupper(char	*str)
{
	int i;

	i = 0;
	while (str[i] != '\0')
	{
		if(str[i] >= 97 && str[i] <= 122)
			str[i] = str[i] - 32;
		i++;
	}
	return (str);
}

void	use_flags_diop(unsigned long int arg, t_flags *pf, char c)
{
	char	*s;
	long	i;
	int		k;

	s = NULL;
	if (c == 'd' || c == 'i')
	{
		i = (long)arg;
		k = (i < 0 ? 1 : 0);
		i = (i < 0 ? -i : i);
		s = ultoa_base(i, 10, k);
	}
	else if (c == 'o')
		s = ultoa_base(arg, 8, 0);
	else if (c == 'u')
		s = ultoa_base(arg, 10, 0);
	else if (c == 'x')
		s = ultoa_base(arg, 16, 0);
	else if (c == 'X')
		s = ft_strtoupper(ultoa_base(arg, 16, 0));
	else if (c == 'p')
		s = ft_strjoin("0x", ultoa_base(arg, 16, 0));
	apply_flags(s, c, pf);
}
