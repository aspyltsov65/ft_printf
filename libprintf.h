/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libprintf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apyltsov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/17 14:56:55 by apyltsov          #+#    #+#             */
/*   Updated: 2018/03/17 14:56:57 by apyltsov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBPRINTF_H
# define LIBPRINTF_H
#include "ft_printf.h"

void	apply_flags(char *s, char c, t_flags *pf);
char	*flag_prec(char	*s, t_flags *pf);
char	*flag_hash(char	*s, char c);
char	*flag_plus_space(char *s, t_flags *pf);
char	*flag_wigth(char *s, char c, t_flags *pf);
char	*flag_min(char *s, t_flags *pf);
void	flag_for_s(char *s, char c, t_flags *pf);
void	flag_wigth_c(char c, t_flags *pf);
void	buff_add(char *s);


#endif
