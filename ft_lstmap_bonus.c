/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnouchet <mnouchet>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/13 01:13:55 by mnouchet          #+#    #+#             */
/*   Updated: 2022/11/14 00:10:21 by mnouchet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*first;
	t_list	*new;
	t_list	*prev;

	first = NULL;
	while (lst)
	{
		new = malloc(sizeof(t_list));
		if (!new)
		{
			ft_lstclear(&first, del);
			return (NULL);
		}
		if (!first)
			first = new;
		new->content = f(lst->content);
		if (prev)
			prev->next = new;
		prev = new;
		lst = lst->next;
	}
	return (first);
}

/*
void * addOne(void * p) {void * r = malloc(sizeof(int)); *(int*)r = *(int*)p + 1; return (r);}

int	main(void)
{
	int tab[] = {0, 1, 2, 3};
	t_list * l =  ft_lstnew(tab);
	for (int i = 1; i < 4; ++i)
		ft_lstadd_back(&l, ft_lstnew(tab + i));
	t_list * m = ft_lstmap(l, addOne, free);
	t_list * tmp = l;
	for (int i = 0; i < 4; ++i)
	{
		printf("\n %d == %d", *(int*)tmp->content, i);
		tmp = tmp->next;
	}
}*/
