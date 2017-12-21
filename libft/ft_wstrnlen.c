/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wstrnlen.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uboumedj <uboumedj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/20 21:00:20 by uboumedj          #+#    #+#             */
/*   Updated: 2017/12/20 21:33:11 by uboumedj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int			ft_wstrnlen(const wchar_t *str, int n)
{
  int   charlen;
	int		len;

	if (!str)
		return (0);
	len = 0;
	while (*str != '\0' && len < n)
	{
		charlen = ft_wcharlen(*str);
		if (len + charlen > n)
			return (len);
		len += charlen;
		str++;
	}
	return (len);
}
