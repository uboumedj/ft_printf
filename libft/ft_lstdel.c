/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uboumedj <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/13 16:18:01 by uboumedj          #+#    #+#             */
/*   Updated: 2017/11/14 15:17:04 by uboumedj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
	t_list	*next;
	t_list	*cur;

	if (alst != NULL)
	{
		cur = *alst;
		while (cur != NULL)
		{
			next = cur->next;
			del(cur->content, cur->content_size);
			free(cur);
			cur = next;
		}
		*alst = NULL;
	}
}
