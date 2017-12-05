/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uboumedj <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/10 12:20:55 by uboumedj          #+#    #+#             */
/*   Updated: 2017/11/10 16:10:15 by uboumedj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

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
