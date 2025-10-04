/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_pipe.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haras <haras@student.42istanbul.com.tr>    #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-10-01 11:53:36 by haras             #+#    #+#             */
/*   Updated: 2025-10-01 11:53:36 by haras            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h"

void	create_pipe(int *fds)
{
	if (pipe(&fds[2]) == -1)
	{
		perror("pipex: pipe creation failed");
		close_multi(fds, 2);
		exit(EXIT_FAILURE);
	}
}
