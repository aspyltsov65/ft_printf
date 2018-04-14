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

int main()
{
	// int a = 10;
	// int *b = &a;
	printf("%lu %lu", sizeof(void*), sizeof(unsigned long long int));
	// ft_printf("hello_my friend %++05");
	//printf("%#x\n", a);
	// printf("%X\n", (unsigned int)b);
	return (0);
}
