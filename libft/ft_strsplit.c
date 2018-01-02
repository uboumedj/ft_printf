/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uboumedj <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/13 19:34:36 by uboumedj          #+#    #+#             */
/*   Updated: 2018/01/02 14:01:17 by uboumedj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		ft_count_words(const char *s, char c)
{
	int		res;
	int		i;

	i = 0;
	res = 0;
	while (s[i])
	{
		if (s[i] != c && (s[i + 1] == c || s[i + 1] == '\0'))
			res++;
		i++;
	}
	return (res);
}

static size_t	ft_wordlen(const char *s, char c)
{
	size_t	len;
	char	*str;

	len = 0;
	str = (char *)s;
	while (*str != '\0' && *str != c)
	{
		len++;
		str++;
	}
	return (len);
}

char			**ft_strsplit(char const *s, char c)
{
	char	**res;
	int		nbw;
	int		i;

	if (s == NULL)
		return (NULL);
	nbw = ft_count_words(s, c);
	if (!(res = (char **)malloc(sizeof(char *) * nbw + 1)))
		return (NULL);
	i = 0;
	while (s && i < nbw)
	{
		while (*s == c && s)
			s++;
		if (!(res[i] = ft_strsub(s, 0, ft_wordlen(s, c))))
			return (NULL);
		i++;
		s += ft_wordlen(s, c);
	}
	res[i] = 0;
	return (res);
}
