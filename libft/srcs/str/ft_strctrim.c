/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strctrim.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uboumedj <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/14 12:19:04 by uboumedj          #+#    #+#             */
/*   Updated: 2018/01/10 15:16:57 by uboumedj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/libft.h"

char	*ft_strctrim(char const *s, char c)
{
	int		len;
	int		i;
	int		j;
	char	*res;

	if (s == NULL)
		return (NULL);
	len = ft_strlen((char *)s);
	while (s[len - 1] && s[len - 1] == c)
		len--;
	i = -1;
	while (s[++i] && s[i] == c)
		len--;
	if (len <= 0)
		len = 0;
	if (!(res = (char *)malloc(sizeof(char) * len + 1)))
		return (NULL);
	j = -1;
	while (++j < len)
		res[j] = s[i + j];
	res[j] = '\0';
	return (res);
}
