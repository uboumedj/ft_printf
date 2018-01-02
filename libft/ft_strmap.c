/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uboumedj <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/10 12:29:20 by uboumedj          #+#    #+#             */
/*   Updated: 2018/01/02 14:01:17 by uboumedj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
{
	char	*res;
	int		len;
	int		i;

	if (s != NULL)
	{
		len = ft_strlen((char *)s);
		if (!(res = (char *)malloc(sizeof(char) * len + 1)))
		{
			return (NULL);
		}
		i = 0;
		while (i < len)
		{
			res[i] = f(s[i]);
			i++;
		}
		res[i] = '\0';
	}
	else
		res = NULL;
	return (res);
}
