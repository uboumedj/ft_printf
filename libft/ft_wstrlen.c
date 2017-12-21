/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wstrlen.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uboumedj <uboumedj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/20 21:34:44 by uboumedj          #+#    #+#             */
/*   Updated: 2017/12/20 21:36:38 by uboumedj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int				ft_wstrlen(const wchar_t *str)
{
  int   len;

  if (!str)
		return (0);
	len = 0;
	while (*str != '\0')
	{
		len += ft_wcharlen(*str);
		str++;
	}
	return (len);
}
