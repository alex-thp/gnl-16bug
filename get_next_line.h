/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ade-temm <ade-temm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/22 14:30:39 by ade-temm          #+#    #+#             */
/*   Updated: 2019/10/29 17:15:49 by ade-temm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <string.h>
# include <unistd.h>

#include <stdio.h>

#define MAX_FD 1024

int     get_next_line(int fd, char **line);
char    *ft_strjoin(char const *s1, char const *s2, int r);
char    *ft_strdup(const char *s1);
size_t  ft_strlen(const char *s);
char    *ft_result(char *result);
char    *ft_next(char *ret, int r);
int     is_n(char *buff);
void    *ft_calloc(size_t count, size_t size);
void    ft_bzero(void *s, size_t n);
char    *ft_substr(char const *s, unsigned int start, size_t len);

#endif