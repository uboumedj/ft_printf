/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uboumedj <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/10 14:00:39 by uboumedj          #+#    #+#             */
/*   Updated: 2018/01/02 14:01:17 by uboumedj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t size)
{
	char	*dst_end;
	size_t	length;

	dst_end = (char *)ft_memchr(dest, '\0', size);
	if (dst_end == NULL)
		return (size + ft_strlen((char *)src));
	length = (size_t)(dst_end - dest) + ft_strlen((char *)src);
	while (*src && (size_t)(dst_end - dest) < size - 1)
	{
		*dst_end = *src;
		dst_end++;
		src++;
	}
	*dst_end = '\0';
	return (length);
}
