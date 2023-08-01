/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mberrouk <mberrouk@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/31 05:56:26 by mberrouk          #+#    #+#             */
/*   Updated: 2023/07/31 06:57:57 by mberrouk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/shell.h"

int len_to_spchar(char *arg)
{
    int len;

    len = 0;
    while (arg[len] && !sp_at_end(arg[len]))
        len++;
    return (len);
}

int	skip_char(char *str, char c)
{
	int i;

	i = 0;
	while (str[i] == c)
		i++;
	return (i);
}
