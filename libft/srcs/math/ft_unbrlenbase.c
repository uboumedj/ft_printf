/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unbrlenbase.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uboumedj <uboumedj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/19 20:47:46 by uboumedj          #+#    #+#             */
/*   Updated: 2018/01/10 15:46:10 by uboumedj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/libft.h"

size_t		ft_unbrlenbase(unsigned long long int nb, unsigned int base)
{
	size_t		res;

	res = 1;
	while (nb >= base)
	{
		nb /= base;
		res++;
	}
	return (res);
}
