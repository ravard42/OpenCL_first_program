/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ravard <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/16 23:44:25 by ravard            #+#    #+#             */
/*   Updated: 2016/01/16 23:47:06 by ravard           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char		*polarity(char *str, int *sign)
{
	if (str[0] == '-')
	{
		*sign = -1;
		return (str + 1);
	}
	else if (str[0] == '+')
	{
		*sign = 1;
		return (str + 1);
	}
	else
	{
		*sign = 1;
		return (str);
	}
}

static int		ft_len(char *buf)
{
	int	i;

	i = 0;
	while (buf[i] >= '0' && buf[i] <= '9')
		i++;
	return (i);
}

int				ft_atoi(const char *str)
{
	char	*buf;
	int		i;
	int		*sign;
	int		len;
	int		result;

	sign = (int *)malloc(sizeof(int));
	buf = (char *)str;
	buf = polarity(ft_rm_whitespace(buf), sign);
	i = 0;
	len = ft_len(buf);
	result = 0;
	while (buf[i] >= '0' && buf[i] <= '9')
	{
		result = result + (buf[i] - '0') * ft_power_ten(len - i - 1);
		i++;
	}
	return (*sign * result);
}
