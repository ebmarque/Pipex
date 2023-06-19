/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebmarque < ebmarque@student.42porto.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/24 19:55:18 by ebmarque          #+#    #+#             */
/*   Updated: 2023/05/25 12:53:16 by ebmarque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	child_process(char *argv[], char *envp[], int *fd)
{
	int	filein;

	filein = open(argv[1], O_RDONLY, 0777);
	if (filein == -1)
		std_error();
	dup2(fd[1], STDOUT_FILENO);
	dup2(filein, STDIN_FILENO);
	close(fd[0]);
	run(argv[2], envp);
}

void	parent_process(char *argv[], char *envp[], int *fd)
{
	int	fileout;

	fileout = open(argv[4], O_WRONLY | O_CREAT | O_TRUNC, 0777);
	if (fileout == -1)
		std_error();
	dup2(fd[0], STDIN_FILENO);
	dup2(fileout, STDOUT_FILENO);
	close(fd[1]);
	run(argv[3], envp);
}

int	main(int argc, char *argv[], char *envp[])
{
	int		fd[2];
	pid_t	process;

	if (argc == 5)
	{
		if (pipe(fd) == -1)
			std_error();
		process = fork();
		if (process == -1)
			std_error();
		if (process == 0)
			child_process(argv, envp, fd);
		waitpid(process, NULL, 0);
		parent_process(argv, envp, fd);
	}
	else
	{
		ft_putstr_fd("Error: Bad arguments\n\e", 2);
		ft_putstr_fd("Ex: ./pipex <file1> <cmd1> <cmd2> <file2>\n", 1);
	}
	return (0);
}
