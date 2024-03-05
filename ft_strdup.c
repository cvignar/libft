/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cvignar <cvignar@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/17 20:55:49 by cvignar           #+#    #+#             */
/*   Updated: 2020/11/24 18:08:35 by cvignar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	size_t	slen;
	char	*s2;

	slen = ft_strlen(s1);
	if (!(s2 = (char *)malloc(sizeof(char) * (slen + 1))))
		return (NULL);
	else
	{
		s2[slen] = '\0';
		while (slen--)
			s2[slen] = s1[slen];
	}
	return (s2);
}
