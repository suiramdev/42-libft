/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnouchet <mnouchet>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/13 01:13:55 by mnouchet          #+#    #+#             */
/*   Updated: 2022/11/13 01:27:35 by mnouchet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new;
	t_list	*prev;
	t_list	*curr;

	while (lst)
	{
		curr = malloc(sizeof(t_list));
		if (new == NULL)
			new = curr;
		if (!curr)
		{
			ft_lstclear(&new, del);
			return (NULL);
		}
		curr->content = f(lst->content);
		if (prev)
			prev->next = curr;
		prev = curr;
		lst = lst->next;
	}
	return (new);
}
