/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mberrouk <mberrouk@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/28 17:24:16 by mberrouk          #+#    #+#             */
/*   Updated: 2023/08/03 10:57:14 by mberrouk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Builtins/builtins.h"
#include <stdlib.h>
#include <readline/readline.h>
#include <readline/history.h>
#include "./include/minishell.h"
#include "./include/shell.h"

/**
 * new_node - Creates a new node for the environment list
 * @key: The key for the environment variable
 * @val: The value for the environment variable
 * @idx: The index of the environment variable
 *
 * Return: A pointer to the newly created node, or NULL on failure
 */
t_env	*new_node(char *key, char *val, int idx)
{
	t_env	*new;

	(void)idx;
	new = malloc(sizeof(t_env));
	if (!new)
		return (0x00);
	new->next = 0x00;
	new->key = key;
	new->val = val;
	return (new);
}

/**
 * add_node - Adds a node to the end of the environment list
 * @lst: A pointer to the head of the environment list
 * @new: A pointer to the node to be added
 */
void	add_node(t_env **lst, t_env *new)
{
	t_env	*tmp;

	if (!lst)
		return ;
	tmp = *lst;
	if (!tmp)
	{
		*lst = new;
		return ;
	}
	while (tmp->next)
		tmp = tmp->next;
	tmp->next = new;
}

/**
 * fetch_env - Fetches the environment variables and creates a linked list
 * @envlist: A pointer to the head of the list
 * @env: The array of environment variables
 */
void	fetch_env(t_env **envlist, char **env)
{
	int		i;
	char	**arg;

	i = 0;
	if (!env)
		return ;
	while (env[i])
	{
		arg = ft_split(env[i], '=');
		if (arg)
			add_node(envlist, new_node(arg[0], arg[1], i));
		i++;
	}
}

void	printf_env(t_env *list_env)
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
	printf("%s\n", av[1]);
	if (av[1] !=  NULL)
	{
		t_info.exit_status = 127;
		printf("env: %s: No such file or directory", av[1]);
		return ;
	}
	t_info.exit_status = 0;
	printf_env(list_env);
}

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
	//printf_env(t_info.g_env);
	// ft_env(envlist, av);
	while (1)
	{
		line = readline("\033[1;34mminishell$  \033[1;0m");;
		if (!line)
		{
			//continue;
			return (EXIT_FAILURE);
		}
		add_history(line);
		if (line && *line)
		{
			init_parse(&cmds, line, env);
			exec_cmds(cmds, 0, env);
		}
		//else {
		//	continue;
		//}
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
