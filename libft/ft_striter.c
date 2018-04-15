/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apyltsov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/11 18:47:38 by apyltsov          #+#    #+#             */
/*   Updated: 2017/11/11 18:47:41 by apyltsov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_striter(char *s, void (*f)(char *))
{
	unsigned int i;

	i = 0;
	if (s != '\0' && f)
		while (s[i] != '\0')
		{
			f(&s[i]);
			i++;
		}
}
