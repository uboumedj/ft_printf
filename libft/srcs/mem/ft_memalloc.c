/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uboumedj <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/10 13:01:27 by uboumedj          #+#    #+#             */
/*   Updated: 2018/01/10 14:59:16 by uboumedj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/libft.h"

void	*ft_memalloc(size_t size)
{
	void	*res;

	if (!(res = (void *)malloc(size)))
	{
		return (NULL);
	}
	ft_bzero(res, size);
	return (res);
}
