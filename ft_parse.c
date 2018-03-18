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

void	ft_parse(const char *format, t_flags *pf)
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
	// ft_specifier(format[i], pf);
}

int		ft_wight_prec(const char *format, t_flags *pf)
{
	int i;

	i = 0;
	if (format[i] == '.')
		pf->prec = ft_atoi(format + i + 1);
	else
		pf->wigth = ft_atoi(format);
	while (ft_isdigit(format[i] == 1))
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
	return (pf->ll == 1 || pf->hh == 1 ? 2 : 1);
}

static void	ft_specifier(char c, t_flags *pf)
{
	long int arg;

	arg = 0;
	if (c == 'p')
		arg = va_arg(pf->argptr, void*);
	else if ( c == 'c')
		if (pf->l)
			arg = va_arg(pf->argptr, int);
		else
			arg = va_arg(pf->argptr, int);
	else if (c =='s')
		if (pf->l)
			arg = va_arg(pf->argptr, wchar_t*);
		else
			arg = va_arg(pf->argptr, char*);
	else if (c == 'd' || c == 'i')
	{
		if (pf->hh)
			arg = (signed char)va_arg(pf->argptr, int);
		else if (pf->h)
			arg = (short int)va_arg(pf->argptr, int);
		else if (pf->l)
			arg = va_arg(pf->argptr, long int);
		else if (pf->ll)
			arg = va_arg(pf->argptr, long long int);
		else if (pf->j)
			arg = va_arg(pf->argptr, intmax_t);
		else if (pf->z)
			arg = va_arg(pf->argptr, size_t);
		else
			arg = va_arg(pf->argptr, int);
	}
	else if (c == 'u' || c == 'o' || c == 'x' || c == 'X')
	{
		if (pf->hh)
			arg = (unsigned int)va_arg(pf->argptr, int);
		else if (pf->h)
			arg = (unsigned short int)va_arg(pf->argptr, int);
		else if (pf->l)
			arg = va_arg(pf->argptr, unsigned long int);
		else if (pf->ll)
			arg = va_arg(pf->argptr, unsigned long long int);
		else if (pf->j)
			arg = va_arg(pf->argptr, uintmax_t);
		else if (pf->z)
			arg = va_arg(pf->argptr, size_t);
		else
			arg = va_arg(pf->argptr, unsigned int);
	}
	use_flags(arg, pf);
}

