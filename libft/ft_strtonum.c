/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtonum.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uboumedj <uboumedj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/17 01:50:27 by uboumedj          #+#    #+#             */
/*   Updated: 2017/12/17 02:01:36 by uboumedj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int   ft_strtonum(char **str, int *res)
{
  int    i;
	int    temp;
	char   *temp_ptr;
	int    neg;

  if (str)
  {
    i = 0;
    temp = 0;
    neg = 1;
    temp_ptr = *str;
		if (*temp_ptr == '-' || *temp_ptr == '+')
		{
			neg = ((*temp_ptr == '-') ? -1 : 1);
			temp_ptr++;
		}
		while (temp_ptr[i] >= '0' && temp_ptr[i] <= '9')
		{
			temp = temp * 10 + (temp_ptr[i] - '0');
			i++;
		}
		*nbr = neg * temp;
		*str = str + i;
		return (i > 0 ? 1 : 0);
	}
	return (0);
}