/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: JeremShy <JeremShy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/10 16:51:55 by jcamhi            #+#    #+#             */
/*   Updated: 2016/03/12 22:18:36 by JeremShy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

int	is_builtin(char *cmd)
{
	if (cmd[0] == 'e')
	{
		if (ft_strequ(cmd, "exit") || ft_strequ(cmd, "env"))
			return (1);
		else
			return (0);
	}
	else if (ft_strequ(cmd, "cd") || ft_strequ(cmd, "setenv") ||
		ft_strequ(cmd, "unsetenv") || ft_strequ(cmd, "source"))
		return (1);
	else
		return (0);
}