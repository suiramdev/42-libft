/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnouchet <mnouchet>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 14:04:51 by mnouchet          #+#    #+#             */
/*   Updated: 2022/11/07 15:06:45 by mnouchet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char		*cpy;
	size_t		i;

	cpy = ft_calloc(len + 1, sizeof(char));
	if (!cpy)
		return (NULL);
	if (start >= ft_strlen(s))
		return (cpy);
	i = 0;
	while (i < len && s[i])
	{
		cpy[i] = s[start + i];
		i++;
	}
	cpy[i] = '\0';
	return (cpy);
}
