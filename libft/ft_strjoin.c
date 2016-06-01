/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ravard <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/17 00:13:28 by ravard            #+#    #+#             */
/*   Updated: 2016/01/17 00:24:31 by ravard           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(const char *s1, const char *s2)
{
	char	*conca;
	int		i;
	int		n1;
	int		n2;

	if (s1 && s2)
	{
		n1 = ft_strlen(s1);
		n2 = ft_strlen(s2);
		if ((conca = (char *)malloc(sizeof(char) * (n1 + n2 + 1))))
		{
			i = -1;
			while (i++ < n1)
				conca[i] = s1[i];
			i = -1;
			while (i++ < n2)
				conca[n1 + i] = s2[i];
			conca[n1 + i] = '\0';
			return (conca);
		}
	}
	return (NULL);
}
