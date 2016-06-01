/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ravard <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/17 00:24:38 by ravard            #+#    #+#             */
/*   Updated: 2016/01/17 00:25:07 by ravard           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *s1, const char *s2, size_t size)
{
	size_t	n;
	size_t	i;

	n = ft_strlen(s1);
	if (size == n)
		return (ft_strlen(s1) + ft_strlen(s2));
	else if (size > n + 1)
	{
		i = 1;
		while (n + i - 1 < size - 1)
		{
			s1[n + i - 1] = s2[i - 1];
			++i;
		}
		s1[n + i - 1] = '\0';
		return (n + ft_strlen(s2));
	}
	else
		return (size + ft_strlen(s2));
}
