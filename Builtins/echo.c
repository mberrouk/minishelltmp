/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoakoumi <hoakoumi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/20 01:01:21 by hoakoumi          #+#    #+#             */
/*   Updated: 2023/07/20 01:14:03 by hoakoumi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builtins.h"
#include "../minishell.h"

int check_option(char *str)
{
    int i = 0;

    if (str[i] == '-' && str[i + 1] != '\0' && str[i + 1] == 'n')
    {
        i++;
        while (str[i])
        {
            if (str[i] == 'n')
                i++;
            else
                return (-1);
        }
        return (0);
    }
    return (-1);
}

void ft_echo(char **av)
{
    int i;
    int flag;

	i = 1;
	flag = 0;
    if (av[i] != NULL && check_option(av[i]) == 0)
    {
        flag = 1;
        i++;  
    }  
    while (av[i])
    {
        printf("%s", av[i]);
        i++;
        if (av[i] != NULL)
            printf(" ");
    }
    if (!flag)
        printf("\n");
    t_info.exit_status = 0;
}

int main(int argc, char **argv)
{
    int i = 0;
    if(argc != 1)
         ft_echo(&argv[i]);
    return (0);
}
