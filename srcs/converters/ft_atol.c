/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suiramdev <marvin@42.fr>                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/22 17:14:45 by suiramdev         #+#    #+#             */
/*   Updated: 2023/02/22 17:15:32 by suiramdev        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

long	ft_atol(const char *nptr)
{
	long	output;
	int		sign;

	while (ft_isspace(*nptr))
		nptr++;
	sign = 1;
	if (*nptr == '-' || *nptr == '+')
	{
		if (*nptr == '-')
			sign = -1;
		nptr++;
	}
	output = 0;
	while (ft_isdigit(*nptr))
	{
		output = output * 10 + (*nptr - '0');
		nptr++;
	}
	return (output * sign);
}
