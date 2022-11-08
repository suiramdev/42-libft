/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnouchet <mnouchet>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/26 00:44:26 by mnouchet          #+#    #+#             */
/*   Updated: 2022/10/27 22:37:28 by mnouchet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, char c)
{
	size_t	i;
	int		imatching;

	i = 0;
	imatching = -1;
	while (s[i])
	{
		if (s[i] == c)
			imatching = i;
		i++;
	}
	if (s[i] == c)
		imatching = i;
	if (imatching < 0)
		return (NULL);
	return ((char *)s + imatching);
}
