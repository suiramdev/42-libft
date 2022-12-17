/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_gnl.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <42.fr>                             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/17 18:58:09 by marvin            #+#    #+#             */
/*   Updated: 2022/12/17 19:05:41 by marvin           ###   ########.fr       */
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

char	*ft_gnl(int fd)
{
	static char	buffer[FOPEN_MAX][BUFFER_SIZE + 1];
	char		*output;
	size_t		i;

	if (fd < 0 || fd > FOPEN_MAX || BUFFER_SIZE < 0)
		return (NULL);
	output = NULL;
	i = 0;
	while (buffer[fd][i] && buffer[fd][i] != '\n')
		i++;
	if (buffer[fd][i] == '\n' && buffer[fd][i + 1])
		ft_strreplace(&output, ft_strnjoin(output, buffer[fd] + i + 1, BUFFER_SIZE));
	clear_buffer(buffer[fd]);
	while (read(fd, buffer[fd], BUFFER_SIZE) > 0)
	{
		i = 0;
		while (buffer[fd][i] && buffer[fd][i] != '\n')
			i++;
		ft_strreplace(&output, ft_strnjoin(output, buffer[fd], i + 1));
		if (buffer[fd][i] == '\n')
			break ;
		clear_buffer(buffer[fd]);
	}
	return (output);
}
