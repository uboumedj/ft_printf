/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uboumedj <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/13 18:03:48 by uboumedj          #+#    #+#             */
/*   Updated: 2017/11/13 18:53:50 by uboumedj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_itoa(int n)
{
	int		len;
	int		temp;
	char	*res;

	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	len = (n <= 0 ? 1 : 0);
	temp = (n < 0 ? -n : n);
	while (temp > 0)
	{
		len++;
		temp /= 10;
	}
	if (!(res = (char *)malloc(sizeof(char) * len + 1)))
		return (NULL);
	res[len--] = '\0';
	temp = (n < 0 ? -n : n);
	while ((temp > 0 && len >= 0) || (n == 0 && len == 0))
	{
		res[len--] = (temp % 10) + '0';
		temp = temp / 10;
	}
	if (n < 0)
		res[len] = '-';
	return (res);
}
