/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnouchet <mnouchet>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 15:08:53 by mnouchet          #+#    #+#             */
/*   Updated: 2022/11/07 16:13:13 by mnouchet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*concat;
	size_t	s1_l;
	size_t	i;

	s1_l = ft_strlen(s1);
	concat = malloc(s1_l + ft_strlen(s2) + 1);
	if (!concat)
		return (NULL);
	i = 0;
	while (s1[i])
	{
		concat[i] = s1[i];
		i++;
	}
	i = 0;
	while (s2[i])
	{
		concat[s1_l + i] = s2[i];
		i++;
	}
	concat[s1_l + i] = '\0';
	return (concat);
}
