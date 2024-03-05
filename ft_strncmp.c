/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cvignar <cvignar@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/16 22:33:35 by cvignar           #+#    #+#             */
/*   Updated: 2020/11/24 21:25:02 by cvignar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strncmp(const char *s1, const char *s2, size_t n)
{
	if (n == 0)
		return (0);
	if (ft_strlen(s1) == ft_strlen(s2) && ft_strlen(s1) < n)
		return (ft_memcmp(s1, s2, ft_strlen(s1)));
	return (ft_memcmp(s1, s2, n));
}
