/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: JeremShy <JeremShy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/11 14:53:03 by JeremShy          #+#    #+#             */
/*   Updated: 2016/03/11 16:08:33 by jcamhi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

static char	*print_error_no_path(char *tmp)
{
	ft_printf("%s%s\n", "Error : The path value in environment",
			" is not valid or inexistant.\n");
	free(tmp);
	return (NULL);
}

static char	*while_exec(char **split, char *scmd)
{
	int		i;
	DIR		*directory;
	t_dirent	*truc;

	i = 0;
	while (split[i])
	{
		directory = opendir(split[i]);
		if (directory)
		{
			while ((truc = readdir(directory)))
				if (ft_strequ(truc->d_name, scmd) &&
						!ft_strequ(truc->d_name, ".") &&
						!ft_strequ(truc->d_name, ".."))
				{
					closedir(directory);
					return (ft_strjoin(ft_strjoinaf1(split[i], "/"), scmd));
				}
			closedir(directory);
		}
		i++;
	}
	ft_printf("minishell: command not found: %s\n", scmd);
	return (NULL);
}

char		*find_exec(char *scmd, t_env *list)
{
	char	**split;
	char	*tmp;

	if (ft_strchr(scmd, '/'))
		return(ft_strdup(scmd));
	tmp = find_arg(list, "PATH");
	if (ft_strequ(tmp, ""))
		return (print_error_no_path(tmp));
	split = ft_strsplit(tmp, ':');
	free(tmp);
	return while_exec(split, scmd);
}

int   exec_file(char **scmd, t_env *list)
{
	char *file;
	char	**env;
	pid_t	process;

	file = find_exec(scmd[0], list);
	env = make_env_char(list);
	process = fork();
	if (process != 0)
		wait(NULL);
	else
		execve(file, scmd, env);
	return (1);
}
