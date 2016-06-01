/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ravard <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/17 00:44:52 by ravard            #+#    #+#             */
/*   Updated: 2016/01/17 00:45:55 by ravard           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(const char *s)
{
	char	*strtrim;

	if (s)
	{
		strtrim = (char *)s;
		strtrim = ft_revstr(ft_rm_whitespace(
					ft_revstr(ft_rm_whitespace(strtrim))));
		return (strtrim);
	}
	return (NULL);
}
