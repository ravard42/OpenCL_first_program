/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ravard <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/17 00:30:35 by ravard            #+#    #+#             */
/*   Updated: 2016/01/17 00:43:15 by ravard           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static t_splitlist		*new_elem(t_splitlist *list_prev, int i, int n)
{
	t_splitlist	*tmp;

	tmp = (t_splitlist *)malloc(sizeof(t_splitlist));
	if (tmp)
	{
		tmp->indice = i;
		tmp->len = n;
		tmp->prev = list_prev;
		tmp->next = NULL;
	}
	return (tmp);
}

static t_splitlist		*load_list(char *str, char c)
{
	t_splitlist		*list[2];
	int				nb[3];

	list[1] = NULL;
	nb[0] = 0;
	while (str && str[nb[0]])
	{
		if (str[nb[0]] == c)
			nb[0]++;
		else
		{
			list[0] = list[1];
			nb[1] = nb[0];
			nb[2] = 0;
			while (str[nb[0]] && str[nb[0]] != c)
			{
				nb[0]++;
				nb[2]++;
			}
			list[1] = new_elem(list[0], nb[1], nb[2]);
			if (list[0] != NULL)
				list[0]->next = list[1];
		}
	}
	return (list[1]);
}

static t_splitlist		*rewind_list(t_splitlist *list, int *nb_words)
{
	int	i;

	if (list)
	{
		i = 1;
		while (list->prev != NULL)
		{
			list = list->prev;
			i++;
		}
		*nb_words = i;
		return (list);
	}
	else
	{
		*nb_words = 0;
		return (NULL);
	}
}

static char				**load_tab(const char *s, int *nb_words,
								t_splitlist *list, char **tab)
{
	int	i;
	int	j;

	i = 0;
	while (i < *nb_words)
	{
		tab[i] = (char *)malloc(sizeof(char) * (list->len + 1));
		j = 0;
		while (j < list->len)
		{
			tab[i][j] = s[list->indice + j];
			j++;
		}
		tab[i][j] = '\0';
		i++;
		list = list->next;
	}
	tab[i] = NULL;
	return (tab);
}

char					**ft_strsplit(const char *s, char c)
{
	int				*nb_words;
	t_splitlist		*list;
	char			**tab;

	nb_words = (int *)malloc(sizeof(int));
	if (nb_words)
	{
		list = rewind_list(load_list((char *)s, c), nb_words);
		tab = (char **)malloc(sizeof(char *) * ((*nb_words) + 1));
		if (tab)
			return (load_tab(s, nb_words, list, tab));
	}
	return (NULL);
}
