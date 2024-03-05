/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cvignar <cvignar@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/24 17:17:48 by cvignar           #+#    #+#             */
/*   Updated: 2020/11/27 18:49:00 by cvignar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_issep(char c, char sep)
{
	if (c == sep)
		return (1);
	return (0);
}

static int	ft_count(char const *s, char c)
{
	int count;

	count = 0;
	while (*s)
	{
		while (*s && ft_issep(*s, c))
			s++;
		if (*s && !(ft_issep(*s, c)))
		{
			count++;
			while (*s && !(ft_issep(*s, c)))
				s++;
		}
	}
	return (count);
}

static char	*ft_new_str(char const *s, char c)
{
	char	*str;
	int		i;

	i = 0;
	while (s[i] && !(ft_issep(s[i], c)))
		i++;
	if (!(str = (char *)malloc(sizeof(char) * (i + 1))))
		return (NULL);
	i = 0;
	while (s[i] && !(ft_issep(s[i], c)))
	{
		str[i] = s[i];
		i++;
	}
	str[i] = '\0';
	return (str);
}

static void	ft_free_all(char **split, int i)
{
	int re;

	re = 0;
	while (re < i)
	{
		free(split[re]);
		re++;
	}
}

char		**ft_split(char const *s, char c)
{
	char	**split;
	int		i;

	if (!s || !(split = (char **)malloc(sizeof(char *) * (ft_count(s, c) + 1))))
		return (NULL);
	i = 0;
	while (*s)
	{
		while (*s && ft_issep(*s, c))
			s++;
		if (*s && !(ft_issep(*s, c)))
		{
			split[i] = ft_new_str(s, c);
			if (split[i] == NULL)
			{
				ft_free_all(split, i);
				return (NULL);
			}
			i++;
			while (*s && !(ft_issep(*s, c)))
				s++;
		}
	}
	split[i] = NULL;
	return (split);
}
