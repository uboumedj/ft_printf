/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uboumedj <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/10 13:34:37 by uboumedj          #+#    #+#             */
/*   Updated: 2017/11/10 14:39:26 by uboumedj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *ptr, int value, size_t len)
{
	unsigned char	*str;
	size_t			i;

	str = (unsigned char *)ptr;
	i = 0;
	while (i < len)
	{
		str[i] = (unsigned char)value;
		i++;
	}
	return (ptr);
}
