/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoakoumi <hoakoumi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/20 01:12:32 by hoakoumi          #+#    #+#             */
/*   Updated: 2023/07/20 01:13:26 by hoakoumi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builtins.h"

t_env	*builtins_main(t_env **list, char **av)
{
	if (ft_strcmp(av[0], "echo") == 0)
		ft_echo(av);
	else if (ft_strcmp(av[0], "pwd") == 0)
		pwd();
	else if (ft_strcmp(av[0], "env") == 0)
		ft_env(*list, av);
	else
		return (NULL);
	return (*list);
}
