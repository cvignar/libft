/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cvignar <cvignar@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/18 00:42:24 by cvignar           #+#    #+#             */
/*   Updated: 2020/11/25 02:48:17 by cvignar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_isneedle(const char *haystack, const char *needle)
{
	size_t j;

	j = 0;
	while (needle[j] != '\0' && haystack[j] == needle[j])
		j++;
	if (needle[j] == '\0')
		return (1);
	return (0);
}

char		*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t i;
	size_t nlen;
	size_t hlen;

	nlen = ft_strlen(needle);
	hlen = ft_strlen(haystack);
	if (needle == 0 || needle == haystack)
		return ((char *)haystack);
	i = 0;
	while (nlen + i < len + 1 && nlen + i < hlen + i)
	{
		if (ft_isneedle((char *)(haystack + i), needle))
			return ((char *)(haystack + i));
		else
			i++;
	}
	return (NULL);
}
