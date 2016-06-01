/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ravard <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/16 23:53:34 by ravard            #+#    #+#             */
/*   Updated: 2016/01/16 23:53:35 by ravard           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
	t_list	*list;
	t_list	*list2;

	list = *alst;
	while (list != NULL)
	{
		del(list->content, list->content_size);
		list2 = list;
		list = list->next;
		free(list2);
	}
	(*alst) = NULL;
}
