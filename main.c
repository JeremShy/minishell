/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcamhi <jcamhi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/09 14:30:14 by jcamhi            #+#    #+#             */
/*   Updated: 2016/03/10 20:49:35 by jcamhi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

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
		ft_printf("$> ");
		get_next_line(0, &cmd);
		get_good_cmd(cmd);
		scmd = ft_strsplit(cmd, ' ');
		if (scmd[0])
		{
			if (is_builtin(scmd[0]) || ft_strequ(scmd[0], "pwd"))
				exec_builtin(scmd, &list);
		}
	}
	return (0);
}
