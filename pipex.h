/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haras <haras@student.42istanbul.com.tr>    #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-10-01 07:57:17 by haras             #+#    #+#             */
/*   Updated: 2025-10-01 07:57:17 by haras            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <sys/wait.h>
# include <stdio.h>

char	**ft_split(char const *s, char c);
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_strdup(const char *s);
char	*ft_substr(char const *s, unsigned int start, size_t len);
size_t	ft_strlen(const char *s);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
void	execute_cmd(char *cmd, char **envp);
void	first_process(int *fds, pid_t *pid, char **argv, char **envp);
void	second_process(int *fds, pid_t *pid, char **argv, char **envp);
void	close_multi(int *fds, int count);
int		open_input_file(const char *filename);
int		open_output_file(const char *filename, int *fds);
void	create_pipe(int *fds);
char	**split_cmd(char *cmd);
char	*find_cmd_path(char *cmd, char **envp);
char	*get_cmd_path(char *cmd, char **envp);
char	*get_path_start(char **envp);
char	*find_executable(char **paths, char *cmd);

#endif
