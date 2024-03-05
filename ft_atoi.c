/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cvignar <cvignar@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/16 22:34:16 by cvignar           #+#    #+#             */
/*   Updated: 2020/11/25 02:49:32 by cvignar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_isspace(char c)
{
	if ((c >= '\t' && c <= '\r') || c == ' ')
		return (1);
	return (0);
}

static int	ft_create_nbr(const char *nptr, int sign)
{
	int						i;
	unsigned long long int	n;

	i = 0;
	n = 0;
	while (nptr[i] != '\0' && (nptr[i] >= '0' && nptr[i] <= '9'))
	{
		n = n * 10 + (nptr[i] - 48);
		i++;
	}
	if (n > 2147483648 && sign == 1)
		return (-1);
	else if (n > 2147483648 && sign == -1)
		return (0);
	return (n * sign);
}

int			ft_atoi(const char *nptr)
{
	int						sign;
	int						i;
	unsigned long long int	n;

	sign = 1;
	n = 1;
	i = 0;
	while (ft_isspace(nptr[i]))
		i++;
	if (nptr[i] == '-')
	{
		sign = -1;
		i++;
	}
	else if (nptr[i] == '+')
		i++;
	n = ft_create_nbr((const char *)(nptr + i), sign);
	return (n);
}
