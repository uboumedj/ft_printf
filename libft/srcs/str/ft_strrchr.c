/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uboumedj <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/10 12:20:55 by uboumedj          #+#    #+#             */
/*   Updated: 2018/01/10 15:16:57 by uboumedj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int i;

	i = ft_strlen((char *)s);
	while (i != 0 && s[i] != c)
	{
		i--;
	}
	if (s[i] == c)
		return ((char *)&s[i]);
	return (NULL);
}
