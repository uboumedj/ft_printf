/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin_i.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uboumedj <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/27 18:21:02 by uboumedj          #+#    #+#             */
/*   Updated: 2017/11/27 18:35:43 by uboumedj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin_i(char const *s1, char const *s2, int i)
{
	char	*res;
	int		len;
	int		i1;
	int		i2;

	if (s1 == NULL || s2 == NULL)
		return (NULL);
	len = ft_strlen(s1) + i;
	if (!(res = (char *)malloc(sizeof(char) * len + 1)))
		return (NULL);
	i1 = 0;
	while (s1[i1] != '\0')
	{
		res[i1] = s1[i1];
		i1++;
	}
	i2 = 0;
	while (s2[i2] != '\0' && i2 < i)
	{
		res[i1] = s2[i2];
		i1++;
		i2++;
	}
	res[i1] = '\0';
	return (res);
}
