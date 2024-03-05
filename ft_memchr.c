/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cvignar <cvignar@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/16 22:29:09 by cvignar           #+#    #+#             */
/*   Updated: 2020/11/28 17:22:59 by cvignar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t i;

	if (n == 0)
		return (NULL);
	i = 0;
	while (i < n && *(unsigned char *)(s + i) != (unsigned char)c)
		i++;
	if (i != n)
		return ((void *)(s + i));
	return (NULL);
}
