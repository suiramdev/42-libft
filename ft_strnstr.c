/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnouchet <mnouchet>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/31 11:42:37 by mnouchet          #+#    #+#             */
/*   Updated: 2022/10/31 14:50:03 by mnouchet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	little_l;
	size_t	i;
	size_t	j;

	little_l = ft_strlen(little);
	if (little_l <= 0)
		return ((char *)big);
	i = 0;
	while (i < len && big[i])
	{
		j = 0;
		while (big[i + j] == little[j] && little[j])
			j++;
		if (j == little_l)
			return ((char *)big + i);
		i++;
	}
	return (NULL);
}
