/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   first_process.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haras <haras@student.42istanbul.com.tr>    #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-10-01 06:44:23 by haras             #+#    #+#             */
/*   Updated: 2025-10-01 06:44:23 by haras            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h"

void	first_process(int *fds, pid_t *pid, char **argv, char **envp)
{
	*pid = fork();
	if (*pid == -1)
	{
		perror("first_fork failed");
		exit(EXIT_FAILURE);
	}
	if (*pid == 0)
	{
		dup2(fds[0], STDIN_FILENO);
		dup2(fds[3], STDOUT_FILENO);
		close_multi(fds, 4);
		execute_cmd(argv[2], envp);
	}
}
