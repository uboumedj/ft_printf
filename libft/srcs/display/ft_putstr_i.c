/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_i.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uboumedj <uboumedj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/15 05:06:43 by uboumedj          #+#    #+#             */
/*   Updated: 2018/01/10 15:09:52 by uboumedj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/libft.h"

void	ft_putstr_i(char const *start, char *end)
{
	char	*tmp;

	tmp = (char *)start;
	while (tmp != end)
	{
		ft_putchar(*tmp);
		tmp++;
	}
}
