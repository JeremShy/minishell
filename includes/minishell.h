/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcamhi <jcamhi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/09 14:31:08 by jcamhi            #+#    #+#             */
/*   Updated: 2016/03/10 20:54:11 by jcamhi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H
# include <ft_printf.h>
# include <libft.h>
# include <dirent.h>
# include <stdlib.h>
# include <unistd.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <sys/types.h>
# include <sys/uio.h>
# include <sys/wait.h>
# include <signal.h>

typedef struct	s_env {
	char			*name;
	char			*arg;
	struct s_env	*next;
}				t_env;

t_env			*ft_parse_env(char **env);
t_env			*add_elem_end(t_env *list, char *name, char *arg);
char			**ft_special_split(char const *s);
char			*get_good_cmd(char *oldcmd);
int				is_builtin(char *cmd);
int				exec_builtin(char **scmd, t_env **env);
void			change_arg(t_env *list, char *name, char *new_arg);
char			*find_arg(t_env *list, char *name);
int				ft_cd(char **scmd, t_env *env);
int				isset_arg(t_env *list, char *name);
void			delete_elem(t_env **list, char *name);
void			delete_list(t_env *list);
#endif
