/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uboumedj <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/10 13:39:20 by uboumedj          #+#    #+#             */
/*   Updated: 2017/11/14 19:12:00 by uboumedj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_memcmp(const void *ptr1, const void *ptr2, size_t n)
{
	size_t	i;

	if (n == 0)
		return (0);
	i = 0;
	while (*(unsigned char *)ptr1 == *(unsigned char *)ptr2 && i < n - 1)
	{
		ptr1++;
		ptr2++;
		i++;
	}
	return (*(unsigned char *)ptr1 - *(unsigned char *)ptr2);
}
