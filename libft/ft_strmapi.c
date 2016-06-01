/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ravard <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/17 00:26:01 by ravard            #+#    #+#             */
/*   Updated: 2016/01/17 00:26:22 by ravard           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(const char *s, char (*f)(unsigned int, char))
{
	char	*buf;
	int		i;

	if (s && f)
	{
		buf = (char *)malloc(sizeof(char) * (ft_strlen(s) + 1));
		if (buf)
		{
			i = 0;
			while (s[i])
			{
				buf[i] = f(i, s[i]);
				i++;
			}
			buf[i] = '\0';
		}
		return (buf);
	}
	return (NULL);
}
