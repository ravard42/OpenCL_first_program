/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ravard <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/16 23:58:19 by ravard            #+#    #+#             */
/*   Updated: 2016/01/16 23:58:38 by ravard           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char		*str1;
	unsigned char		*str2;
	size_t				i;

	if (n != 0)
	{
		str1 = (unsigned char *)s1;
		str2 = (unsigned char *)s2;
		i = 0;
		while (i < n - 1 && str1[i] == str2[i])
			i++;
		return (str1[i] - str2[i]);
	}
	return (0);
}
