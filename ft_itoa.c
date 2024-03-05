/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cvignar <cvignar@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/24 17:23:57 by cvignar           #+#    #+#             */
/*   Updated: 2020/11/25 02:46:46 by cvignar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_rank(unsigned int n)
{
	int i;

	i = 0;
	if (n > 9)
	{
		while (n / 10 != 0)
		{
			n = n / 10;
			i++;
		}
		i++;
	}
	else if (n <= 9 && n > 0)
		i = 1;
	return (i);
}

static char	*ft_link_nbr(unsigned int n, int minus)
{
	char			*nbr;
	unsigned int	nb;
	int				i;

	nb = n;
	i = ft_rank(n);
	minus == 1 ? (i += 1) : (i += 0);
	if (!(nbr = (char *)malloc(sizeof(char) * i + 1)))
		return (NULL);
	if (minus == 1)
		nbr[0] = '-';
	nbr[i] = '\0';
	i--;
	while (nb / 10 > 0)
	{
		nbr[i] = nb % 10 + 48;
		nb = nb / 10;
		i--;
	}
	if (nb / 10 == 0)
		nbr[i] = nb % 10 + 48;
	i = 0;
	return (nbr);
}

char		*ft_itoa(int n)
{
	char	*nbr;
	int		minus;

	minus = 0;
	if (n == 0)
	{
		if (!(nbr = (char *)malloc(sizeof(char) * 2)))
			return (NULL);
		nbr[0] = n + 48;
		nbr[1] = '\0';
	}
	else if (n < 0)
	{
		minus++;
		return (ft_link_nbr((unsigned int)(-n), minus));
	}
	else
		return (ft_link_nbr(n, minus));
	return (nbr);
}
