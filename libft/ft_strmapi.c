/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uboumedj <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/10 12:32:36 by uboumedj          #+#    #+#             */
/*   Updated: 2017/11/13 15:35:27 by uboumedj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char				*res;
	unsigned int		len;
	unsigned int		i;

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
			res[i] = f(i, s[i]);
			i++;
		}
		res[i] = '\0';
	}
	else
		res = NULL;
	return (res);
}
