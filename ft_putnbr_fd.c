/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cvignar <cvignar@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/24 17:23:17 by cvignar           #+#    #+#             */
/*   Updated: 2020/11/25 02:47:53 by cvignar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_write_nbr_fd(unsigned int n, int fd)
{
	char	c[10];
	int		d;
	int		i;
	int		sw;

	c[0] = '\0';
	d = 1000000000;
	i = 0;
	sw = 0;
	while (i < 10)
	{
		c[i] = n / d + 48;
		if (c[i] != '0')
			sw++;
		if (sw > 0)
			write(fd, &c[i], 1);
		n = n % d;
		d = d / 10;
		i++;
	}
}

void		ft_putnbr_fd(int n, int fd)
{
	if (n == 0)
		write(fd, "0", 1);
	if (n < 0)
	{
		write(fd, "-", 1);
		ft_write_nbr_fd((unsigned int)(-n), fd);
	}
	else
	{
		ft_write_nbr_fd(n, fd);
	}
}
