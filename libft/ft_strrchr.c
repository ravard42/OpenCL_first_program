/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ravard <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/17 00:30:11 by ravard            #+#    #+#             */
/*   Updated: 2016/01/17 00:30:24 by ravard           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	*str;
	char	d;
	int		n;
	int		i;

	str = (char *)s;
	d = (char)c;
	n = ft_strlen(s);
	i = 1;
	if (str[n] == '\0' && d == '\0')
		return (str + n);
	while (i <= n && str[n - i])
	{
		if (str[n - i] == d)
			return (str + n - i);
		else
			i++;
	}
	return (NULL);
}
