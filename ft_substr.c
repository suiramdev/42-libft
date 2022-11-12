/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnouchet <mnouchet>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 14:04:51 by mnouchet          #+#    #+#             */
/*   Updated: 2022/11/12 13:44:42 by mnouchet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	s_len;
	size_t	output_len;
	char	*output;
	size_t	i;

	output_len = 0;
	s_len = ft_strlen(s);
	if (start <= s_len)
	{
		output_len = s_len - start;
		if (len < output_len)
			output_len = len;
	}
	output = ft_calloc(output_len + 1, sizeof(char));
	if (!output)
		return (NULL);
	i = 0;
	while (i < output_len && s[i + start])
	{
		output[i] = s[i + start];
		i++;
	}
	return (output);
}
