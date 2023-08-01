/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expansion_analysis.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mberrouk <mberrouk@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/31 05:54:30 by mberrouk          #+#    #+#             */
/*   Updated: 2023/07/31 20:56:02 by mberrouk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/shell.h"

char *expan_in_dquots(char *arg, char **env);
char *pars_arg_expan(char *arg, char **env);
int	sp_to_skip(char c);
int	_strncmp(char *s1, char *s2, int n);
int	check_sp_char(char c);
int    sp_at_end(char ch);
int    sp_remove(char ch);

int skip_dollar(char **value, char *arg)
{
    int i;

    i = 0;
    while (arg[i] == '$')
	{
		if (i && !((i + 1) % 2))
            *value = ft_strjoin(*value, "$$");				/** use ft_strdup for $$ **/
		else if (!arg[i + 1])
			*value =  ft_realloc(*value, '$');
		i++;
    }	
	printf("~~~~~~~> %s | value :: %s | i :: %d\n", arg, *value, i);
    return (i);
}


char	*expan_arg(char *arg, char *env[])
{
    int     i;
	int		len;
    char    *value;

    i = 0;
    value = ft_strdup("");
    while (arg[i])
    {
        if (arg[i] && check_sp_char(arg[i]))
        {
			printf("*******> %s\n", value);
			
		if (arg[i] == '\'' || arg[i] == '\"' || arg[i] == '$')
			return (value);
			i += handl_spchar_cases(&arg[i], &value);
			//continue;
        }
		else
		{
			len = len_to_spchar(&arg[i]);
			value = ft_strjoin(value, get_var(ft_substr(&arg[i], 0, len), env));
			i += len;
		}
		while (arg[i] != '$' && arg[i] != '\'' && arg[i] != '\"' && arg[i])
		{
			value = ft_realloc(value, arg[i]); 
			i++;
		}
		if (arg[i] == '\'' || arg[i] == '\"' || arg[i] == '$')
			return (value);
	}
	printf("............-->  %s\n", value);
    return (value);
}

char *continue_pars(char **env, char *arg, int *index, char sep)
{
	int		ndolr;
    int     i;
    int     start;
	char	*value;

    i = 0;
    value = NULL;
	ndolr = skip_dollar(&value, arg);
    i += ndolr;
    start = ndolr ? ndolr : 0;
	if(sep == '$' && (arg[i] == '\'' || arg[i] == '\"'))
	{
		*index += i;
		return (value);
	}
	printf("arg --- > %s\n", arg);
	while (arg[i])
    {
        i++;
        if ((arg[i] == sep || !arg[i] || (sep == '$' && (arg[i] == '\'' || arg[i] == '\"'))))
        {
        	if (sep == '\"')
        		value = ft_strjoin(value, expan_in_dquots(ft_substr(arg, 0, i + 1), env));
        	else if (sep == '\'')
            	value = ft_strjoin(value, ft_substr(arg, 0, i + 1));
        	else if (sep == '$' && ndolr % 2 != 0)
            {
				printf("-=-------->> %s\n", value);
                value = ft_strjoin(value, expan_arg(ft_substr(arg, start, i - 1), env));
				printf("-=-------->> %s\n", value);
            }
            else
            {
                value = ft_strjoin(value, ft_substr(arg, start, i - start));
            }
            if (arg[i] && ((sep == '\'' && arg[i] == '\'') || (sep == '\"' && arg[i] == '\"')))
					i++;
                break;
        }
    }
    *index += i;
	return (value);
}

char *pars_arg_expan(char *arg, char **env)
{
    int i;
    int s;
    char sep;
    char *value;
    
    i = 0;
    value = NULL;
    while (arg[i])
    {
        if (arg[i] == '\"' || arg[i] == '$' || arg[i] == '\'')
        {
            sep = arg[i];
            s = i;
			value = ft_strjoin(value, continue_pars(env, &arg[i], &i, sep));
        	printf("??? %s\n", value);
		}
        else
		{
			printf("---as\n");
            value = ft_realloc(value, arg[i]);
    		i++;
		}
	}
    return (value);
}

