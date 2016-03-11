/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: JeremShy <JeremShy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/09 14:30:14 by jcamhi            #+#    #+#             */
/*   Updated: 2016/03/11 14:55:22 by JeremShy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

static void print_prompt(void)
{
	char	*new;

	new = getcwd(NULL, 0);
	ft_printf("<%s>%% ", new);
	free(new);
}

int main(int ac, char **av, char **env)
{
	t_env	*list;
	char	*cmd;
	char	**scmd;

	if (ac > 1)
		exit((ft_printf("Usage : %s\n", av[0])));
	list = ft_parse_env(env);
	while (1)
	{
		print_prompt();
		get_next_line(0, &cmd);
		get_good_cmd(cmd);
		scmd = ft_strsplit(cmd, ' ');
		if (scmd[0])
		{
			if (is_builtin(scmd[0]))
				exec_builtin(scmd, &list);
			else
				exec_file(scmd, list);
		}
	}
	return (0);
}
