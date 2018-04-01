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
#include <locale.h>

int main()
{
	char	r[5] = "hello";
	int a = 2378;
	int	c = 3456789;
	char	y = 't';
	// int *b = &a;
	// char *str = NULL;
	// unsigned int b = -23;
	// setlocale(LC_ALL, "");
	// printf("%010x\n", 542);
	// ft_printf("my\n%010x\n", 542);

	// printf("%#08x\n", 42);
	// ft_printf("my\n%#08x\n", 42);
// ok
	printf("@moulitest: %.x %.0x\n", 0, 0);
	ft_printf("my @moulitest: %.x %.0x\n\n", 0, 0);

	printf("@moulitest: %#5.x %#5.0x\n", 0, 0);
	ft_printf("my @moulitest: %#5.x %#5.0x\n", 0, 0);

	// printf("|%010.7s|\n", r);
	// ft_printf("%-10c\n", y);
	//printf("%#x\n", a);
	// printf("%X\n", (unsigned int)b);
	return (0);
}


