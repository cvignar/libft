/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cvignar <cvignar@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/17 21:01:02 by cvignar           #+#    #+#             */
/*   Updated: 2020/11/25 00:44:41 by cvignar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	void *ptr;

	if (count == 0 && size != 0)
	{
		if (!(ptr = malloc(size)))
			return (NULL);
	}
	else if (size == 0 && count != 0)
	{
		if (!(ptr = malloc(count)))
			return (NULL);
	}
	else if (count == 0 && size == 0)
	{
		if (!(ptr = malloc(1)))
			return (NULL);
	}
	else
	{
		if (!(ptr = malloc(count * size)))
			return (NULL);
	}
	ft_bzero(ptr, count * size);
	return (ptr);
}
