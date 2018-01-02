/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uboumedj <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/13 18:56:21 by uboumedj          #+#    #+#             */
/*   Updated: 2018/01/02 14:01:17 by uboumedj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s)
{
	char	*res;
	int		len;
	int		i;
	int		j;

	if (s != NULL)
	{
		len = ft_strlen((char *)s);
		while (ft_isspace(s[len - 1]) && s[len - 1])
			len--;
		i = -1;
		while (s[++i] && ft_isspace(s[i]))
			len--;
		if (len <= 0)
			len = 0;
		if (!(res = (char *)malloc(sizeof(char) * len + 1)))
			return (NULL);
		j = -1;
		while (++j < len)
			res[j] = s[i + j];
		res[j] = '\0';
	}
	else
		res = NULL;
	return (res);
}
