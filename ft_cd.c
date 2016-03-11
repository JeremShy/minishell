/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cd.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcamhi <jcamhi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/10 18:38:42 by jcamhi            #+#    #+#             */
/*   Updated: 2016/03/10 18:49:48 by jcamhi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

static int chg_arg1(char **scmd, t_env *env, char *tmp)
{
	char	*new;

	if (chdir(scmd[1]) == 0)
	{
		new = getcwd(NULL, 0);
		change_arg(env, "OLDPWD", tmp);
		change_arg(env, "PWD", new);
		free(new);
		free(tmp);
		return (1);
	}
	else
	{
		ft_printf("chdir failed\n");
		free(tmp);
		return (0);
	}
}

int	ft_cd(char **scmd, t_env *env)
{
	char	*tmp;
	char	*temp;

	tmp = getcwd(NULL, 0);
	if (!scmd[1])
	{
		change_arg(env, "OLDPWD", tmp);
		change_arg(env, "PWD", find_arg(env, "HOME"));
		chdir(find_arg(env, "HOME"));
	}
	else if (!ft_strequ(scmd[1], "-"))
		return(chg_arg1(scmd, env, tmp));
	else
	{
		temp = ft_strdup(find_arg(env, "OLDPWD"));
		change_arg(env, "OLDPWD", find_arg(env, "PWD"));
		change_arg(env, "PWD", temp);
		chdir(temp);
		free(temp);
	}
	free(tmp);
	return (1);
}