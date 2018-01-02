/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uboumedj <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/13 19:42:48 by uboumedj          #+#    #+#             */
/*   Updated: 2018/01/02 14:01:17 by uboumedj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *s1, const char *s2, size_t len)
{
	size_t	i;
	size_t	j;
	size_t	count;

	i = 0;
	count = 0;
	if (ft_strcmp((char *)s2, "") == 0)
		return ((char *)s1);
	while (s1[i] && count < len)
	{
		j = 0;
		while ((s1[i + j] && s2[j] == s1[i + j]) && i + j < len)
			j++;
		if (s2[j] == '\0')
			return ((char *)&(s1[i]));
		i++;
		count++;
	}
	return (NULL);
}
