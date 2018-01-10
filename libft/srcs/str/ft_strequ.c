/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strequ.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uboumedj <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/10 13:52:31 by uboumedj          #+#    #+#             */
/*   Updated: 2018/01/10 15:16:57 by uboumedj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/libft.h"

int		ft_strequ(char const *s1, char const *s2)
{
	if (s1 != NULL && s2 != NULL)
		return (!ft_strcmp((char *)s1, (char *)s2));
	else
		return (0);
}
