/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrev.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uboumedj <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/15 17:20:46 by uboumedj          #+#    #+#             */
/*   Updated: 2018/01/10 15:16:57 by uboumedj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/libft.h"

char	*ft_strrev(char *str)
{
	char	*res;
	size_t	len;
	int		i;

	if (str != NULL)
	{
		len = ft_strlen(str);
		if (!(res = (char *)malloc(sizeof(char) * len + 1)))
			return (NULL);
		i = 0;
		while (len != 0)
		{
			res[i] = str[len - 1];
			i++;
			len--;
		}
		res[i] = '\0';
	}
	else
		res = NULL;
	return (res);
}
