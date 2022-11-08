/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnouchet <mnouchet>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/29 00:35:00 by mnouchet          #+#    #+#             */
/*   Updated: 2022/10/31 15:06:54 by mnouchet         ###   ########.fr       */
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
	i = 0;
	while (i < size - dst_l - 1 && src[i])
	{
		dst[i + dst_l] = src[i];
		i++;
	}
	if (size > 0)
		dst[i + dst_l] = '\0';
	if (dst_l < src_l)
		return (src_l + dst_l);
	return (size + src_l);
}
