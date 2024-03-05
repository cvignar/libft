/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cvignar <cvignar@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/09 19:27:51 by cvignar           #+#    #+#             */
/*   Updated: 2020/11/26 19:07:03 by cvignar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		ft_isset(char const *set, char c)
{
	size_t i;

	i = 0;
	while (set[i] != '\0')
	{
		if (c == set[i])
			return (1);
		else
			i++;
	}
	return (0);
}

static size_t	start(char const *s1, char const *set)
{
	size_t start;

	start = 0;
	while (ft_isset(set, s1[start]) && s1[start] != '\0')
		start++;
	return (start);
}

static size_t	end(char const *s1, char const *set, size_t len)
{
	size_t end;

	end = len;
	if (end > 0)
	{
		end = end - 1;
		while (ft_isset(set, s1[end]) && end)
			end--;
	}
	return (end);
}

static char		*ft_trim_s1(char const *s1, size_t i, size_t j)
{
	size_t	k;
	char	*str;

	if (i <= j)
	{
		if (!(str = (char *)malloc(sizeof(char) * (j - i + 2))))
			return (NULL);
	}
	else if (i > j || (i == 0 && j == 0))
	{
		if (!(str = (char *)malloc(sizeof(char) * 1)))
			return (NULL);
	}
	k = 0;
	while (i <= j)
	{
		str[k] = s1[i];
		i++;
		k++;
	}
	str[k] = '\0';
	return (str);
}

char			*ft_strtrim(char const *s1, char const *set)
{
	size_t	i;
	size_t	j;
	char	*trimmed;

	j = 0;
	if (!s1)
		return (NULL);
	if (!set)
		return ((char *)s1);
	i = start(s1, set);
	j = end(s1, set, ft_strlen(s1));
	trimmed = ft_trim_s1(s1, i, j);
	return (trimmed);
}
