/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_cmd.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haras <haras@student.42istanbul.com.tr>    #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-10-01 09:28:52 by haras             #+#    #+#             */
/*   Updated: 2025-10-01 09:28:52 by haras            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h"

void	execute_cmd(char *cmd, char **envp)
{
	char	**args;
	char	*path;

	args = split_cmd(cmd);
	path = find_cmd_path(args[0], envp);
	if (execve(path, args, envp) == -1)
	{
		perror("pipex: execve failed");
		exit(EXIT_FAILURE);
	}
}
