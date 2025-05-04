/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: babyf <babyf@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/03 15:43:15 by babyf             #+#    #+#             */
/*   Updated: 2025/05/04 21:37:59 by babyf            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
#define PIPEX_H

#include "../include/libft.h"
#include "ft_printf.h"
#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>
#include <stdio.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>

char	*get_path(char **envp);
char	*check_cmd(char **paths, char *cmd);
char	*find_path(char *cmd, char **envp);
void	execute(char *cmd, char **envp);
void	create_child_process(char *cmd, char **envp, int *fd, int infile);
void	create_parent_process(char *cmd, char **envp, int *fd, int outfile);
void	child_process(char *cmd, char **envp, int *fd, int infile);
void	parent_process(char *cmd, char **envp, int *fd, int outfile);
char	*ft_strjoin_free(char *s1, char *s2);
void	initialize_files(char *in_path, char *out_path, int *infile, int *outfile);

#endif