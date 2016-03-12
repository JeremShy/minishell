/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: JeremShy <JeremShy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/09 14:30:14 by jcamhi            #+#    #+#             */
/*   Updated: 2016/03/12 01:03:22 by jcamhi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

static void print_prompt(void)
{
	char		*new;


	new = getcwd(NULL, 0);
	ft_printf("<%s>%% ", new);
	free(new);
}

static void	exec_cmd(char **scmd, t_env **env)
{
	if (scmd[0])
	{
		if (is_builtin(scmd[0]))
			exec_builtin(scmd, env);
		else
			exec_file(scmd, *env);
	}
}

int main(int ac, char **av, char **env)
{
	t_env	*list;
	char	*cmd;
	char	**scmd;

	if (ac > 1)
	{
		ft_putstr_fd("Usage : ", 2);
		ft_putstr_fd(av[0], 2);
		ft_putstr_fd("\n", 2);
		return (0);
	}
	list = ft_parse_env(env);
	while (1)
	{
		print_prompt();
		get_next_line(0, &cmd);
		get_good_cmd(cmd);
		scmd = ft_strsplit(cmd, ' ');
		exec_cmd(scmd, &list);
	}
	return (0);
}
