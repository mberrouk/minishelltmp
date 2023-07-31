/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoakoumi <hoakoumi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/20 01:03:46 by hoakoumi          #+#    #+#             */
/*   Updated: 2023/07/20 01:19:33 by hoakoumi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builtins.h"
#include "../minishell.h"

void printf_env(t_env *list_env)
{
    while (list_env != NULL)
    {
        if (list_env->val != NULL)
        {
            printf("%s=%s\n", list_env->key, list_env->val);
        }
        list_env = list_env->next;
    }
}


void	ft_env(t_env *list_env, char **av)
{
	if (av[1] !=  NULL)
	{
		t_info.exit_status = 127;
		printf("env: %s: No such file or directory", av[1]);
		return ;
	}
	t_info.exit_status = 0;
	printf_env(list_env);
}