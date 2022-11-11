/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnouchet <mnouchet>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/29 00:35:00 by mnouchet          #+#    #+#             */
/*   Updated: 2022/11/11 11:23:42 by mnouchet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	src_l;
	size_t	dst_l;
	size_t	i;

	src_l = ft_strlen(src);
	dst_l = ft_strlen(dst);
	if (dst_l >= size - 1 || size <= 0)
		return (size + src_l);
	i = 0;
	while (i < size - dst_l - 1 && src[i])
	{
		dst[i + dst_l] = src[i];
		i++;
	}
	dst[i + dst_l] = '\0';
	return (dst_l + src_l);
}
