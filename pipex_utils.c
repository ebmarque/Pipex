/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebmarque < ebmarque@student.42porto.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/24 20:03:24 by ebmarque          #+#    #+#             */
/*   Updated: 2023/05/27 14:12:01 by ebmarque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	std_error(void)
{
	perror("ERROR");
	exit(EXIT_FAILURE);
}

void	custom_error(char *header, char *msg)
{
	ft_putstr_fd(header, 2);
	ft_putstr_fd(": ", 2);
	ft_putstr_fd(msg, 2);
	ft_putstr_fd("\n", 2);
}

char	*get_path(char *cmd, char *envp[])
{
	char	**paths;
	char	*path;
	char	*path_tobe;
	int		i;

	i = 0;
	paths = NULL;
	while (ft_strnstr(envp[i], "PATH=", 5) == 0)
		i++;
	paths = ft_split(envp[i] + 5, ':');
	i = -1;
	while (paths[++i])
	{
		path_tobe = ft_strjoin(paths[i], "/");
		path = ft_strjoin(path_tobe, cmd);
		free(path_tobe);
		if (access(path, F_OK) == 0)
			return (path);
		free(path);
	}
	i = -1;
	while (paths[++i])
		free(paths[i]);
	custom_error(cmd, "command not found");
	return (0);
}

void	run(char *argv, char *envp[])
{
	char	**cmd;
	char	*path;
	int		i;

	i = 0;
	cmd = ft_split(argv, ' ');
	path = get_path(cmd[0], envp);
	if (!path)
	{
		while (cmd[i])
		{
			free(cmd[i]);
			i++;
		}
		free(cmd);
		exit(EXIT_FAILURE);
	}
	if (execve(path, cmd, envp) == -1)
		std_error();
}
