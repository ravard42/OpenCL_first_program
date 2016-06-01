/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ravard <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/16 23:55:46 by ravard            #+#    #+#             */
/*   Updated: 2016/01/18 15:34:17 by ravard           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list		*ft_lstnew(const void *content, size_t content_size)
{
	t_list	*lstnew;
	void	*dst;

	lstnew = (t_list *)malloc(sizeof(t_list));
	if (lstnew)
	{
		if (content)
		{
			dst = malloc(content_size);
			dst = ft_memcpy(dst, content, content_size);
			lstnew->content = dst;
			lstnew->content_size = content_size;
		}
		else
		{
			lstnew->content = NULL;
			lstnew->content_size = 0;
		}
		lstnew->next = NULL;
		return (lstnew);
	}
	return (NULL);
}
