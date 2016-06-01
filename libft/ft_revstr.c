/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_revstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ravard <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/17 00:05:49 by ravard            #+#    #+#             */
/*   Updated: 2016/01/17 00:06:10 by ravard           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_revstr(char *str)
{
	int		n;
	int		i;
	char	*revstr;

	if (str)
	{
		n = ft_strlen(str);
		revstr = (char *)malloc(sizeof(char) * n + 1);
		if (revstr)
		{
			i = 0;
			while (i < n)
			{
				revstr[i] = str[n - i - 1];
				i++;
			}
			revstr[i] = '\0';
			return (revstr);
		}
	}
	return (NULL);
}
