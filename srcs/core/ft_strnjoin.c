/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnjoin.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <42.fr>                             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/17 19:02:13 by marvin            #+#    #+#             */
/*   Updated: 2022/12/17 19:05:00 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnjoin(char *s1, char *s2, size_t n)
{
	size_t	s1_len;
	char	*output;
	size_t	i;

	s1_len = ft_strlen(s1);
	output = malloc(s1_len + n + 1);
	if (!output)
		return (NULL);
	i = 0;
	if (s1)
		while (*s1)
			output[i++] = *(s1++);
	while (*s2 && i - s1_len < n)
		output[i++] = *(s2++);
	output[i] = '\0';
	return (output);
}
