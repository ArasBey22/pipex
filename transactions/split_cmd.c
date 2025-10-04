/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_cmd.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haras <haras@student.42istanbul.com.tr>    #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-10-01 09:25:09 by haras             #+#    #+#             */
/*   Updated: 2025-10-01 09:25:09 by haras            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h"

char	**split_cmd(char *cmd)
{
	char	**args;

	args = ft_split(cmd, ' ');
	if (!args || !args[0])
	{
		perror("pipex: empty command");
		exit(EXIT_FAILURE);
	}
	return (args);
}
