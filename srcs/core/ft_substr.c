/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnouchet <mnouchet>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 14:04:51 by mnouchet          #+#    #+#             */
/*   Updated: 2022/11/14 15:42:06 by mnouchet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	s_len;
	size_t	output_len;
	char	*output;
	size_t	i;

	s_len = ft_strlen(s);
	output_len = 0;
	while (output_len + start < s_len && output_len < len)
		output_len++;
	output = malloc(output_len + 1);
	if (!output)
		return (NULL);
	i = 0;
	while (i < output_len && i + start < s_len)
	{
		output[i] = s[i + start];
		i++;
	}
	output[i] = '\0';
	return (output);
}
