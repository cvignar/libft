/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cvignar <cvignar@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/17 13:50:06 by cvignar           #+#    #+#             */
/*   Updated: 2020/11/25 00:22:42 by cvignar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t		ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	if (src == NULL)
		return (0);
	if (ft_strlen(src) + 1 >= dstsize && dstsize)
	{
		ft_memcpy(dst, src, (dstsize - 1));
		dst[dstsize - 1] = '\0';
	}
	else if (ft_strlen(src) + 1 < dstsize && dstsize)
		ft_memcpy(dst, src, ft_strlen(src) + 1);
	return (ft_strlen(src));
}
