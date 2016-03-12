/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: JeremShy <JeremShy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/09 14:30:14 by jcamhi            #+#    #+#             */
/*   Updated: 2016/03/12 20:35:16 by JeremShy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

static void print_prompt(t_env *env)
{
	char	*new;

	new = getcwd(NULL, 0);
	if (!new)
	{
		change_arg(env, "PWD", find_arg(env, "HOME"));
		chdir(find_arg(env, "HOME"));
		new = getcwd(NULL, 0);
	}
	ft_printf("<%s>%% ", new);
	free(new);
}

void	exec_cmd(char *cmd, t_env **env)
{
	char **scmd;

	scmd = ft_special_split(cmd);
	free(cmd);
	if (scmd[0])
	{
		if (is_builtin(scmd[0]))
			exec_builtin(scmd, env);
		else
			exec_file(scmd, *env);
	}
}

static void	exec_mshrc(t_env **env)
{
	char **scmd;

	scmd = malloc(3 * sizeof(char*));
	scmd[0] = ft_strdup("source");
	scmd[1] = ft_strjoinaf1(ft_strjoin(find_arg(*env, "HOME"), "/"), ".mshrc");
	scmd[2] = ft_strdup("");
	ft_source(scmd, env);
	free(scmd[0]);
	free(scmd[1]);
	free(scmd[2]);
	free(scmd);
}

int main(int ac, char **av, char **env)
{
	t_env	*list;
	char	*cmd;

	if (ac > 1)
	{
		ft_putstr_fd("Usage : ", 2);
		ft_putstr_fd(av[0], 2);
		ft_putstr_fd("\n", 2);
		return (0);
	}
	list = ft_parse_env(env);
	exec_mshrc(&list);
	while (1)
	{
		print_prompt(list);
		get_next_line(0, &cmd);
		exec_cmd(cmd, &list);
	}	
	return (0);
}
