/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   second_process.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haras <haras@student.42istanbul.com.tr>    #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-10-01 06:45:35 by haras             #+#    #+#             */
/*   Updated: 2025-10-01 06:45:35 by haras            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h"

void	second_process(int *fds, pid_t *pid, char **argv, char **envp)
{
	*pid = fork();
	if (*pid == -1)
	{
		perror("second_fork failed");
		exit(EXIT_FAILURE);
	}
	if (*pid == 0)
	{
		dup2(fds[2], STDIN_FILENO);
		dup2(fds[1], STDOUT_FILENO);
		close_multi(fds, 4);
		execute_cmd(argv[3], envp);
	}
}
