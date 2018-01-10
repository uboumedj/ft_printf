/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wstrlen.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uboumedj <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/02 13:41:59 by uboumedj          #+#    #+#             */
/*   Updated: 2018/01/10 18:09:52 by uboumedj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/libft.h"

int				ft_wstrlen(const wchar_t *str)
{
	int		len;
	int		i;

	if (!str)
		return (0);
	len = 0;
	i = 0;
	while (str[i] != '\0')
	{
		len += ft_wcharlen(str[i]);
		i++;
	}
	return (len);
}
