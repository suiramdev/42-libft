/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnouchet <mnouchet>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 17:42:41 by mnouchet          #+#    #+#             */
/*   Updated: 2022/11/09 16:42:53 by mnouchet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_digits(unsigned int n)
{
	size_t	digits;

	if (n == 0)
		return (1);
	digits = 0;
	while (n > 0)
	{
		digits++;
		n /= 10;
	}
	return (digits);
}

char	*ft_itoa(int n)
{
	int			negative;
	size_t		digits;
	char		*output;
	size_t		i;

	negative = n < 0;
	if (negative)
		n = -n;
	digits = ft_digits(n);
	output = malloc(digits + negative + 1);
	if (!output)
		return (NULL);
	if (negative)
		output[0] = '-';
	i = digits;
	while (i > 0)
	{
		output[i - 1 + negative] = '0' + n % 10;
		n /= 10;
		i--;
	}
	output[digits + negative] = '\0';
	return (output);
}
