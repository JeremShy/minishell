/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_source.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: JeremShy <JeremShy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/12 14:53:20 by JeremShy          #+#    #+#             */
/*   Updated: 2016/03/12 22:22:50 by JeremShy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

int ft_source(char **scmd, t_env **env)
{
	int		fd;
	char	*cmd;
	int		i;
	char	**cmd_tab;

	if (scmd[1] == '\0')
		return (0);
	fd = open(scmd[1], O_RDONLY);
	if (fd == -1)
		return (0);
	while (get_next_line(fd, &cmd))
	{
		cmd_tab = ft_strsplit(cmd, ';');
		i = 0;
		while (cmd_tab[i])
		{
			exec_cmd(cmd_tab[i], env);
			i++;
		}
		free(cmd_tab);
		free(cmd);
	}
	return (1);
}