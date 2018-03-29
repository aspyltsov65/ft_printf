/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apyltsov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/22 18:34:29 by apyltsov          #+#    #+#             */
/*   Updated: 2018/02/22 18:34:31 by apyltsov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>
# include "libft/libft.h"

# define BUFF_SIZE 4096

char	*g_buff;
int		g_i;

typedef struct 	s_flags
{
	int			min;
	int			plus;
	int			space;
	int			hash;
	int			zero;
	int			h;
	int			hh;
	int			l;
	int			ll;
	int			j;
	int			z;
	int 		wigth;
	int			flag_w;
	int			prec;
	int			flag_p;
}				t_flags;

int		ft_printf(const char *format, ...);
int		ft_parse(const char *format, t_flags *pf, va_list argptr);
int		ft_wight_prec(const char *format, t_flags *pf);
int		ft_length(const char *format, t_flags *pf);
void	ft_specifier(char c, t_flags *pf, va_list argptr);
void	use_flags_diop(unsigned long arg, t_flags *pf, char c);
char	*ultoa_base(unsigned long int num, int base, int flag);
char	*ft_strtoupper(char	*str);


#endif