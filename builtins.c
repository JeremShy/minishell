/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcamhi <jcamhi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/10 16:57:59 by jcamhi            #+#    #+#             */
/*   Updated: 2016/03/10 17:38:09 by jcamhi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

int	ft_cd(char **scmd, t_env *env)
{
	char	*tmp;

	tmp = getcwd(NULL, 0);
	if (!scmd[1])
	{
		change_arg(env, "OLDPWD", tmp);
		change_arg(env, "PWD", find_arg(env, "HOME"));
		chdir(find_arg(env, "HOME"));
	}
	else if (!ft_strcmp(scmd[1], "-"))
	{
		if (chdir(scmd[1]))
		{
			change_arg(env, "OLDPWD", tmp);
			change_arg(env, "PWD", scmd[1]);
		}
		else
			return (0);
	}
	else
		return (0);
	free(tmp);
	return (1);
}

int	ft_env(t_env *env)
{
	while (env)
	{
		ft_printf("%s=%s\n", env->name, env->arg);
		env = env->next;
	}
	return (1);
}

int	exec_builtin(char **scmd, t_env *env)
{
	if (ft_strequ(scmd[0], "cd"))
		return (ft_cd(scmd, env));
	else if (ft_strequ(scmd[0], "env"))
		return (ft_env(env));
	else if (ft_strequ(scmd[0], "pwd"))
		ft_printf("%s\n",getcwd(NULL, 0));
	return(0);
}