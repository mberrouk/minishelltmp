/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mberrouk <mberrouk@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/28 17:24:16 by mberrouk          #+#    #+#             */
/*   Updated: 2023/08/04 22:46:20 by mberrouk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./include/shell.h"

int	main(int ac, char *av[], char *env[])
{
	(void)av;
	t_cmd	*cmds;
	char	*line;

	if (ac != 1)
		return (1);
	line = NULL;
	cmds = NULL;
	fetch_env(&t_info.g_env, env);
	while (1)
	{
		line = readline("\033[1;34mminishell$  \033[1;0m");;
		if (!line)
		{
			//continue;
			return (errno);
		}
		add_history(line);
		if (line && *line)
		{
			init_parse(&cmds, line, env);
			exec_cmds(cmds, 0, env);
		}
		clean_parss(&cmds);
	}

	/**
	 * Test 
	for (int i = 0; envlist; i++)
	{
		printf("env : %s\n", env[i]);
		printf("envlst : %s %s\n", envlist->key, envlist->val);
		envlist = envlist->next;
	}
	*/
}
