/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apyltsov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/22 17:52:21 by apyltsov          #+#    #+#             */
/*   Updated: 2018/02/22 17:52:23 by apyltsov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "ft_printf.h"
#include <stdlib.h>

int main()
{
	char	r[5] = "hello";
	int a = 2378;
	int	c = 3456789;
	char	y = 't';
	// int *b = &a;
	// char *str = NULL;
	// unsigned int b = -23;
	printf("%-10c\n", y);
	// printf("|%010.7s|\n", r);
	ft_printf("%-10c\n", y);
	//printf("%#x\n", a);
	// printf("%X\n", (unsigned int)b);
	return (0);
}


