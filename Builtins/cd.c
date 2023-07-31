/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoakoumi <hoakoumi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/20 01:22:14 by hoakoumi          #+#    #+#             */
/*   Updated: 2023/07/20 01:25:19 by hoakoumi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builtins.h"
#include "../minishell.h"

int	ft_strcmp(const char *s1, const char *s2)
{
	size_t			i;
	unsigned char	*c;
	unsigned char	*l;

	i = 0;
	c = (unsigned char *)s1;
	l = (unsigned char *)s2;
	if (!s1 && !s2)
		return (0);
	while (c[i] != '\0' || l[i] != '\0' )
	{
		if (c[i] != l[i])
			return (c[i] - l[i]);
		i++;
	}
	return (0);
}

t_env	*searching_key(t_env *env_list, char *key)
{
	while (env_list)
	{
		if (ft_strcmp(key, env_list->key) == 0)
			return (env_list);
		env_list = env_list->next;
	}
	return (NULL);
}

t_env   *ft_cd(t_env **env_list, char *new_dir_path)
{
	char buf[100];
    int     res;
    t_env   *output;

    if (new_dir_path!= NULL)
	{
		res = chdir(new_dir_path);
		printf("%s\n",getcwd(buf, sizeof(buf)));
	}
        
    else
    {
        output = searching_key(*env_list, "HOME");
        if (output == NULL)
        {
            printf("bash: cd: HOME not set");
            t_info.exit_status = 1;
        }
        else
        {
            // cd et cd -- -> donne -> HOME
            // cd * et cd ** ??
        }
    }
    

}

// int main()
// {
//     char puf[100];
//     ft_cd("/Users/hoakoumi/Desktop/mini");
//     getcwd(puf, sizeof(puf));
//     printf("%s\n", puf);
// }