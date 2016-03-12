/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: JeremShy <JeremShy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/12 17:46:16 by jcamhi            #+#    #+#             */
/*   Updated: 2016/03/12 17:46:37 by JeremShy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

char	*get_good_cmd(char *oldcmd)
{
	char	*cmd;
	char	**split;
	int		i;

	i = 1;
	split = ft_special_split(oldcmd);
	if (!split[0])
		return (ft_strdup(""));
	cmd = ft_strdup(split[0]);
	while (split[i])
	{
		cmd = ft_strjoinaf1(cmd, " ");
		cmd = ft_strjoinaf1(cmd, split[i]);
		i++;
	}
	return (cmd);
}
