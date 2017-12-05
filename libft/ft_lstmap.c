/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uboumedj <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/13 17:00:30 by uboumedj          #+#    #+#             */
/*   Updated: 2017/11/14 17:01:20 by uboumedj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*res;
	t_list	*flst;
	t_list	*nxt;

	if (lst == NULL || f == NULL)
		return (NULL);
	flst = f(lst);
	if (!(nxt = ft_lstnew(flst->content, flst->content_size)))
		return (NULL);
	res = nxt;
	lst = lst->next;
	while (lst)
	{
		flst = f(lst);
		if (!(nxt->next = ft_lstnew(flst->content, flst->content_size)))
			return (NULL);
		nxt = nxt->next;
		lst = lst->next;
	}
	return (res);
}
