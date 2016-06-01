/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ravard <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/17 00:44:05 by ravard            #+#    #+#             */
/*   Updated: 2016/01/17 00:44:07 by ravard           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *big, const char *little)
{
	int	n;
	int	i;
	int	j;

	n = ft_strlen(big);
	if (little[0] == '\0')
		return ((char *)big);
	i = 0;
	while (i < n)
	{
		j = 0;
		while (little[j] && little[j] == big[i + j])
			j++;
		if (little[j] == '\0')
			return ((char *)big + i);
		else
			i++;
	}
	return (NULL);
}
