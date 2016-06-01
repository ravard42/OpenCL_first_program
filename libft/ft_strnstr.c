/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ravard <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/17 00:29:40 by ravard            #+#    #+#             */
/*   Updated: 2016/01/17 00:30:03 by ravard           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	n;
	size_t	i;
	size_t	j;

	n = ft_strlen(big);
	if (little[0] == '\0')
		return ((char *)big);
	if (len >= ft_strlen(little))
	{
		i = 0;
		while (i < n && i < len - ft_strlen(little) + 1)
		{
			j = 0;
			while (little[j] && little[j] == big[i + j])
				j++;
			if (little[j] == '\0')
				return ((char *)big + i);
			else
				i++;
		}
	}
	return (NULL);
}
