/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnouchet <mnouchet>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 11:43:40 by mnouchet          #+#    #+#             */
/*   Updated: 2022/11/10 16:16:59 by mnouchet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	unsigned int	unsigned_n;
	char			output;

	unsigned_n = n;
	if (n < 0)
	{
		unsigned_n = -n;
		write(fd, "-", 1);
	}
	output = '0' + unsigned_n % 10;
	unsigned_n = unsigned_n / 10;
	if (unsigned_n > 0)
		ft_putnbr_fd(unsigned_n, fd);
	write(fd, &output, 1);
}
