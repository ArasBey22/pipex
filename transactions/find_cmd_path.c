/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_cmd_path.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haras <haras@student.42istanbul.com.tr>    #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-10-01 09:26:47 by haras             #+#    #+#             */
/*   Updated: 2025-10-01 09:26:47 by haras            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h"

char	*find_cmd_path(char *cmd, char **envp)
{
	char	*path;

	path = get_cmd_path(cmd, envp);
	if (!path)
	{
		perror("pipex: command not found");
		exit(127);
	}
	return (path);
}
