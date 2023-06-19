/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_utils_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebmarque < ebmarque@student.42porto.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/25 13:12:27 by ebmarque          #+#    #+#             */
/*   Updated: 2023/05/27 13:28:59 by ebmarque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	bad_args(void)
{
	ft_putstr_fd("Error: Bad argument\n", 2);
	ft_putstr_fd("Ex: ./pipex <file1> <cmd1> "
		"<cmd2> <...> <file2>\n", 1);
	ft_putstr_fd("    ./pipex \"here_doc\""
		"<LIMITER> <cmd> <cmd1> <...> <file>\n", 1);
	exit(EXIT_SUCCESS);
}

int	get_next_line(char **line)
{
	char	*buffer;
	int		i;
	int		r;
	char	c;

	i = 0;
	r = 0;
	buffer = (char *)malloc(10000);
	if (!buffer)
		return (-1);
	r = read(0, &c, 1);
	while (r && c != '\n' && c != '\0')
	{
		if (c != '\n' && c != '\0')
			buffer[i] = c;
		i++;
		r = read(0, &c, 1);
	}
	buffer[i] = '\n';
	buffer[++i] = '\0';
	*line = buffer;
	free(buffer);
	return (r);
}
