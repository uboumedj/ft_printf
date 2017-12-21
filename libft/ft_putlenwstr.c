/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putlenwstr.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uboumedj <uboumedj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/20 21:46:30 by uboumedj          #+#    #+#             */
/*   Updated: 2017/12/20 21:49:00 by uboumedj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void ft_putlenwstr(wchar_t *str, int len)
{
  int		i;

	if (str)
	{
		i = 0;
		while (str[i] != '\0' && i < len)
		{
			ft_putwchar(str[i]);
			i++;
		}
	}
}
