/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cvignar <cvignar@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/18 01:20:25 by cvignar           #+#    #+#             */
/*   Updated: 2020/11/28 17:53:33 by cvignar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	char	*substr;

	if (!s)
		return (NULL);
	if (start >= ft_strlen(s))
	{
		if (!(substr = (char *)ft_calloc(sizeof(char), 1)))
			return (NULL);
	}
	else
	{
		i = start;
		if (!(substr = (char *)malloc(sizeof(char) * len + 1)))
			return (NULL);
		ft_strlcpy(substr, (char const *)(s + i), len + 1);
	}
	return (substr);
}
