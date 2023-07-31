/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pwd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoakoumi <hoakoumi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/11 06:03:00 by hoakoumi          #+#    #+#             */
/*   Updated: 2023/07/20 01:09:08 by hoakoumi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builtins.h"
#include "../minishell.h"

void	pwd(void)
{
	char	puf[10];

	if (getcwd(puf, sizeof(puf)) == NULL)
		perror("error :");
	else
		printf("%s\n", puf);
	t_info.exit_status = 0;
}
