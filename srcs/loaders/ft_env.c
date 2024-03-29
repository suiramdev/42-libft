/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_env.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnouchet <mnouchet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 23:30:12 by mnouchet          #+#    #+#             */
/*   Updated: 2023/02/05 00:25:33 by mnouchet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

extern char	**environ;

char	**ft_env(char *name)
{
	char	**env;
	size_t	i;

	env = environ;
	while (env && *env)
	{
		i = 0;
		while (*(*env + i) == name[i])
			i++;
		if (*(*env + i) == '=')
			return (ft_split(*env + i + 1, ':'));
		env++;
	}
	return (NULL);
}
