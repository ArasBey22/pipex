/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haras <haras@student.42istanbul.com.tr>    #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-10-01 06:43:39 by haras             #+#    #+#             */
/*   Updated: 2025-10-01 06:43:39 by haras            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	main(int argc, char **argv, char **envp)
{
	int		fds[4];
	pid_t	pids[2];

	if (argc != 5)
	{
		write(2, "Usage: ./pipex file1 cmd1 cmd2 file2\n", 38);
		exit(EXIT_FAILURE);
	}
	fds[0] = open_input_file(argv[1]);
	fds[1] = open_output_file(argv[4], fds);
	create_pipe(fds);
	first_process(fds, &pids[0], argv, envp);
	second_process(fds, &pids[1], argv, envp);
	close_multi(fds, 4);
	waitpid(pids[0], NULL, 0);
	waitpid(pids[1], NULL, 0);
	return (0);
}
