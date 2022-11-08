/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnouchet <mnouchet>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/26 01:35:49 by mnouchet          #+#    #+#             */
/*   Updated: 2022/10/28 00:50:56 by mnouchet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/* The difference between memcpy and memmove is not always apparent:
 * One always copies in the forward direction ↵
 * the other in the reverse direction if dest < src
 * We will notice its usefulness when src and dest overlap.
 *
 * N.B.: This overlapping error is automatically fixed by some compilers.
 * */
void	*ft_memmove(void *dest, const void *src, size_t n)
{
	size_t	i;

	if (dest < src)
		return (ft_memcpy(dest, src, n));
	i = n;
	while (i > 0)
	{
		((char *)dest)[i - 1] = ((char *)src)[i - 1];
		i--;
	}
	return (dest);
}
