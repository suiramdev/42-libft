/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnouchet <mnouchet>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/31 11:51:34 by mnouchet          #+#    #+#             */
/*   Updated: 2022/10/31 12:40:27 by mnouchet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *nptr)
{
	int		output;
	int		negative;
	size_t	i;

	output = 0;
	negative = 1;
	i = 0;
	while (ft_isspace(nptr[i]))
		i++;
	if (ft_issign(nptr[i]))
	{
		if (nptr[i] == '-')
			negative = -negative;
		i++;
	}
	while (ft_isdigit(nptr[i]))
	{
		output *= 10;
		output += nptr[i] - '0';
		i++;
	}
	return (output * negative);
}
