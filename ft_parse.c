/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apyltsov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/08 17:49:01 by apyltsov          #+#    #+#             */
/*   Updated: 2018/03/08 17:49:12 by apyltsov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h> //////////////////////////////////////////////////////////

int		ft_parse(const char *format, t_flags *pf, va_list argptr)
{
	int 	i;

	i = 0;
	while (format[i])
	{
		if (format[i] == '-')
			pf->min = 1;
		else if (format[i] == '+')
			pf->plus = 1;
		else if (format[i] == ' ')
			pf->space = 1;
		else if (format[i] == '#')
			pf->hash = 1;
		else if (format[i] == '0')
			pf->zero = 1;
		else
			break;
		i++;
	}
	if (ft_isdigit(format[i]) == 1)
		i = i + ft_wight_prec(format + i, pf);
	if (format[i] == '.')
		i = i + ft_wight_prec(format + i, pf);
	i = i + ft_length(format + i, pf);
	ft_specifier(format[i], pf, argptr);
	return (i + 1);
}

int		ft_wight_prec(const char *format, t_flags *pf)
{
	int i;

	i = 0;
	if (format[i] == '.')
	{
		pf->flag_p = 1;
		pf->prec = ft_atoi(format + i + 1);
		i++;
	}
	else
	{
		pf->flag_w = 1;
		pf->wigth = ft_atoi(format);
	}
	while (ft_isdigit(format[i]) == 1)
		i++;
	return (i);
}

int		ft_length(const char *format, t_flags *pf)
{
	int i;

	i = 0;
	if(format[i] == 'h')
		if(format[i + 1] != '\0' && format[i + 1] == 'h')
			pf->hh = 1;
		else
			pf->h = 1;
	else if (format[i] == 'l')
		if (format[i + 1] != '\0' && format[i + 1] == 'l')
			pf->ll = 1;
		else
			pf->l = 1;
	else if (format[i] == 'j')
		pf->j = 1;
	else if (format[i] == 'z')
		pf->z = 1;
	else
		return(0);
	return (pf->ll == 1 || pf->hh == 1 ? 2 : 1);
}

void	ft_specifier(char c, t_flags *pf, va_list argptr)
{
	char	*s;

	// system ("leaks a.out");
	if (c == 'p')
		use_flags_diop(va_arg(argptr, size_t), pf, c);
	else if (c == 'c' || c == 'C')
	{
		if (pf->l == 1 || c == 'C')
			unicode_lc(va_arg(argptr, int), pf);
		else
			flag_wigth_c((char)(va_arg(argptr, int)), pf);
	}

	else if (c =='s' || c =='S')
	{
		if (c == 'S')
			pf->l = 1;
		if (pf->l)
			unicode_ls(va_arg(argptr, int *), pf);
		else
			flag_for_s(va_arg(argptr, char *), c, pf);
	}
	else if (c == 'd' || c == 'i' || c == 'D')
	{
		if(c == 'D')
			pf->l = 1;
		if (pf->z)
			use_flags_diop(va_arg(argptr, size_t), pf, c);
		else if (pf->j)
			use_flags_diop(va_arg(argptr, intmax_t), pf, c);
		else if (pf->ll)
			use_flags_diop(va_arg(argptr, long long int), pf, c);		
		else if (pf->l)
			use_flags_diop(va_arg(argptr, long int), pf, c);	
		else if (pf->h)
			use_flags_diop((short int)va_arg(argptr, int), pf, c);
		else if (pf->hh)
			use_flags_diop((signed char)va_arg(argptr, int), pf, c);
		else
		{
			use_flags_diop(va_arg(argptr, int), pf, c);
			// while(1)
			// 	;
		}
	}
	else if (c == 'u' || c == 'o' || c == 'x' || c == 'X' || c == 'O' ||
	c == 'U')
	{
		if(c == 'U' || c == 'O')
			pf->l = 1;
		if (pf->z)
			use_flags_diop(va_arg(argptr, size_t), pf, c);
		else if (pf->j)
			use_flags_diop(va_arg(argptr, uintmax_t), pf, c);
		else if (pf->ll)
			use_flags_diop(va_arg(argptr, unsigned long long int), pf, c);
		else if (pf->l)
			use_flags_diop(va_arg(argptr, unsigned long int), pf, c);
		else if (pf->h)
			use_flags_diop((unsigned short int)va_arg(argptr, int), pf, c);
		else
			use_flags_diop(va_arg(argptr, unsigned int), pf, c);
	}
	else
	{
		s = ft_strnew(1);
		s[0] = c;
		pf->flag_p = 0;
		apply_flags(s, c, pf);
		// ft_strdel(&s);
		// while (1)
		// 	;
	}
	// while (1)
	// 	;
}
