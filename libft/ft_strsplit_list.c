/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ravard <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/17 00:30:35 by ravard            #+#    #+#             */
/*   Updated: 2016/04/14 13:23:13 by ravard           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static t_list				*load_return_list(char **tab,
								int n, t_list **return_list)
{
	int		i;
	t_list	*buf;

	i = n;
	if ((buf = (t_list *)malloc(sizeof(t_list))))
	{
		buf = ft_lstnew(tab[i], ft_strlen(tab[i]) + 1);
		*return_list = buf;
		i--;
		while (i != -1)
		{
			buf = ft_lstnew(tab[i], ft_strlen(tab[i]) + 1);
			ft_lstadd(return_list, buf);
			i--;
		}
		return (*return_list);
	}
	return (NULL);
}

t_list						*ft_strsplit_list(const char *s, char c)
{
	int				n;
	char			**tab;
	t_list			**return_list;

	tab = ft_strsplit(s, c);
	if (tab && tab[0])
	{
		n = -1;
		while (tab[n + 1])
			n++;
		return_list = (t_list **)malloc(sizeof(t_list *));
		if (return_list)
			return (load_return_list(tab, n, return_list));
	}
	return (NULL);
}
