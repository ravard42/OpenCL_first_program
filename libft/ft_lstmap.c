/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ravard <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/16 23:54:26 by ravard            #+#    #+#             */
/*   Updated: 2016/01/16 23:55:17 by ravard           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*first;
	t_list	*new;

	first = (t_list *)malloc(sizeof(t_list));
	if (first && lst)
	{
		first = f(lst);
		new = (t_list *)malloc(sizeof(t_list));
		if (new)
		{
			new = first;
			lst = lst->next;
			while (lst != NULL)
			{
				new->next = f(lst);
				new = new->next;
				lst = lst->next;
			}
			return (first);
		}
	}
	return (NULL);
}
