/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnouchet <mnouchet>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 17:42:41 by mnouchet          #+#    #+#             */
/*   Updated: 2022/11/10 11:16:49 by mnouchet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_digits(unsigned int n)
{
	size_t	count;

	if (n == 0)
		return (1);
	count = 0;
	while (n > 0)
	{
		count++;
		n /= 10;
	}
	return (count);
}

char	*ft_itoa(int n)
{
	unsigned int	unsigned_n;
	int				negative;
	size_t			digits;
	char			*output;
	size_t			i;

	unsigned_n = n;
	negative = n < 0;
	if (negative)
		unsigned_n = -n;
	digits = ft_digits(unsigned_n);
	output = malloc(digits + negative + 1);
	if (!output)
		return (NULL);
	if (negative)
		output[0] = '-';
	i = digits;
	while (i > 0)
	{
		output[i - 1 + negative] = '0' + unsigned_n % 10;
		unsigned_n /= 10;
		i--;
	}
	output[digits + negative] = '\0';
	return (output);
}
