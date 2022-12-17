/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnouchet <mnouchet>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 16:14:07 by mnouchet          #+#    #+#             */
/*   Updated: 2022/11/12 13:58:44 by mnouchet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	start;
	size_t	end;
	char	*output;

	start = 0;
	while (ft_strchr(set, s1[start]) != NULL && s1[start])
		start++;
	end = ft_strlen(s1) - 1;
	while (ft_strchr(set, s1[end]) != NULL && end > 0)
		end--;
	if (start > end)
	{
		output = malloc(1);
		if (!output)
			return (NULL);
		output[0] = '\0';
		return (output);
	}
	output = malloc(end - start + 2);
	if (!output)
		return (NULL);
	ft_strlcpy(output, s1 + start, end - start + 2);
	return (output);
}
