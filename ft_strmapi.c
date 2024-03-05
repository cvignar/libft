/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cvignar <cvignar@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/24 17:21:11 by cvignar           #+#    #+#             */
/*   Updated: 2020/11/25 01:00:10 by cvignar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char			*dst;
	unsigned int	i;

	i = 0;
	if (!s)
	{
		if (!(dst = (char *)malloc(sizeof(char) * 1)))
			return (NULL);
	}
	else
	{
		if (!(dst = (char *)malloc(sizeof(char) * ft_strlen(s) + 1)))
			return (NULL);
		while (s[i] != '\0')
		{
			dst[i] = f(i, s[i]);
			i++;
		}
	}
	dst[i] = '\0';
	return (dst);
}
