/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ravard <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/16 23:50:47 by ravard            #+#    #+#             */
/*   Updated: 2016/01/16 23:52:54 by ravard           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int			ordre_de_grandeur(int n)
{
	int	i;

	i = 1;
	while (n != 0)
	{
		n = n / 10;
		i++;
	}
	return (i);
}

static int			init_k_n(int *k, int n)
{
	if (n < 0)
	{
		*k = -1;
		n = -n;
	}
	else if (n == 0)
		*k = 0;
	else
		*k = 1;
	return (n);
}

static void			fin_de_chaine(char *str, int i, int *k)
{
	if (*k == -1)
	{
		str[i] = '-';
		str[i + 1] = '\0';
	}
	else if (*k == 0)
	{
		str[i] = '0';
		str[i + 1] = '\0';
	}
	else
	{
		str[i] = '\0';
	}
}

static char			*int_min_value(void)
{
	char	*str;

	str = (char *)malloc(sizeof(char) * 12);
	if (str)
		str = ft_strcpy(str, "-2147483648");
	return (str);
}

char				*ft_itoa(int n)
{
	int		i;
	int		*k;
	char	*str;

	if (n == -2147483648)
		return (int_min_value());
	i = 0;
	k = (int *)malloc(sizeof(int));
	if (k)
	{
		n = init_k_n(k, n);
		str = (char *)malloc(sizeof(char) * (ordre_de_grandeur(n) + 2));
		if (str && k)
		{
			while (n != 0)
			{
				str[i] = '0' + (n % 10);
				n = n / 10;
				i++;
			}
			fin_de_chaine(str, i, k);
			return (ft_revstr(str));
		}
	}
	return (NULL);
}
