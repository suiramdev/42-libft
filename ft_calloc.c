/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnouchet <mnouchet>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/31 16:10:01 by mnouchet          #+#    #+#             */
/*   Updated: 2022/10/31 16:23:32 by mnouchet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*ptr;
	size_t	i;

	if (nmemb > 0 && size > 0)
		ptr = malloc(nmemb * size);
	else
		ptr = malloc(0);
	if (!ptr)
		return (NULL);
	i = 0;
	while (*((char *)ptr + i))
	{
		*((char *)ptr + i) = 0;
		i++;
	}
	return (ptr);
}
