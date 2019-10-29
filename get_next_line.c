/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ade-temm <ade-temm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/29 17:13:04 by ade-temm          #+#    #+#             */
/*   Updated: 2019/10/29 17:13:11 by ade-temm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int             get_next_line(int fd, char **line)
{
    static char     *result[MAX_FD];
    char            *buff;
    int             r;
    r = 1;
    if (!result[fd])
        if (!(result[fd] = ft_calloc(sizeof(char), 1)))
            return (-1);
    if (!(buff = ft_calloc(sizeof(char), BUFFER_SIZE)))
        return (-1);
    if (fd < 0)
        return (-1);
    printf("mon stockage = %s\n", result[fd]);
    while (r != 0 && is_n(result[fd]) == -1)
    {
        r = read(fd, buff, BUFFER_SIZE);
        if (r < 0)
            return (-1);
        buff[r] = '\0';
        result[fd] = ft_strjoin(result[fd], buff, r);
        printf("result[fd] dans le while : %s\n", result[fd]);
    }
    *line = ft_result(result[fd]);
    //printf("*line = %s\n", *line);
    free(buff);
    result[fd] = ft_next(result[fd], r);
    printf("ft_next = %s\n", result[fd]);
    return ((r == 0 && is_n(result[fd]) == -1) ? 0 : 1);
}
