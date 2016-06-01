/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ravard <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/17 00:29:21 by ravard            #+#    #+#             */
/*   Updated: 2016/01/17 00:29:22 by ravard           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnew(size_t size)
{
	size_t	i;
	char	*strnew;

	strnew = (char *)malloc(size + 1);
	if (strnew)
	{
		i = 0;
		while (i < size + 1)
		{
			strnew[i] = '\0';
			i++;
		}
		return (strnew);
	}
	return (NULL);
}
