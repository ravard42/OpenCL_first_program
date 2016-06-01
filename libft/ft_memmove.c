/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ravard <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/17 00:00:19 by ravard            #+#    #+#             */
/*   Updated: 2016/04/14 13:23:24 by ravard           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	char		*dst0;
	const char	*src0;
	int			i;

	dst0 = (char *)dst;
	src0 = (const char *)src;
	if (dst0 < src0)
	{
		i = 0;
		while (i < (int)len)
		{
			dst0[i] = src0[i];
			i++;
		}
	}
	else if (dst0 > src0)
	{
		i = (int)len - 1;
		while (i != -1)
		{
			dst0[i] = src0[i];
			i--;
		}
	}
	return (dst);
}
