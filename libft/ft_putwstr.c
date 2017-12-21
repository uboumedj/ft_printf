/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putwstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uboumedj <uboumedj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/20 20:37:23 by uboumedj          #+#    #+#             */
/*   Updated: 2017/12/20 20:38:00 by uboumedj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void 			ft_putwstr(wchar_t const *str)
{
  int i;

	if (str != NULL)
	{
		i = 0;
		while (str[i])
		{
			ft_putwchar(str[i]);
			i++;
		}
	}
}
