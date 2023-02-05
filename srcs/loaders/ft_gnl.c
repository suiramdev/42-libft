/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_gnl.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnouchet <mnouchet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 00:35:43 by mnouchet          #+#    #+#             */
/*   Updated: 2023/02/06 00:37:53 by mnouchet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	clear_buffer(char buffer[BUFFER_SIZE + 1])
{
	size_t	i;

	i = 0;
	while (i < BUFFER_SIZE + 1)
	{
		buffer[i] = '\0';
		i++;
	}
}

// Something is wrong here, when the BUFFER_SIZE is too large,
// it fucked fdf maps.
char	*ft_gnl(int fd)
{
	static char	buffer[BUFFER_SIZE + 1];
	char		*output;
	size_t		i;

	if (fd < 0 || fd > FOPEN_MAX || BUFFER_SIZE < 0)
		return (NULL);
	output = NULL;
	i = 0;
	while (buffer[i] && buffer[i] != '\n')
		i++;
	if (buffer[i] == '\n' && buffer[i + 1])
		ft_memrep((void **)&output,
			ft_strnjoin(output, buffer + i + 1, BUFFER_SIZE));
	clear_buffer(buffer);
	while (read(fd, buffer, BUFFER_SIZE) > 0)
	{
		i = 0;
		while (buffer[i] && buffer[i] != '\n')
			i++;
		ft_memrep((void **)&output, ft_strnjoin(output, buffer, i + 1));
		if (buffer[i] == '\n')
			break ;
		clear_buffer(buffer);
	}
	return (output);
}
