/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uboumedj <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/10 12:38:16 by uboumedj          #+#    #+#             */
/*   Updated: 2017/11/14 19:15:01 by uboumedj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *str1, const char *str2)
{
	int i;
	int j;

	i = 0;
	if (!(*str2))
		return ((void *)str1);
	while (str1[i])
	{
		j = 0;
		while (str1[i + j] == str2[j] && str1[i + j] != '\0')
		{
			j++;
		}
		if (!(str2[j]))
		{
			return ((char *)&(str1[i]));
		}
		i++;
	}
	return (NULL);
}
