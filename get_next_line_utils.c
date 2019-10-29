/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ade-temm <ade-temm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/29 17:12:36 by ade-temm          #+#    #+#             */
/*   Updated: 2019/10/29 17:12:39 by ade-temm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "get_next_line.h"
void    ft_bzero(void *s, size_t n)
{
    size_t i;
    i = 0;
    while (i < n)
    {
        *(char*)s = '\0';
        s++;
        i++;
    }
}
void    *ft_calloc(size_t count, size_t size)
{
    void    *result;
    if (count == 0 || size == 0)
        return (NULL);
    if (!(result = malloc(count * size)))
        return (NULL);
    ft_bzero(result, (size * count));
    return (result);
}
size_t  ft_strlen(const char *s)
{
    size_t  i;
    i = 0;
    while (s[i])
        i++;
    return (i);
}
char    *ft_strjoin(char const *s1, char const *s2, int r)
{
    int     i;
    int     j;
    char    *result;
    
    i = ft_strlen(s1);
    j = ft_strlen(s2);
    //printf("i : %d j : %d total : %d\n", i , j, i + j);
    if (!(result = ft_calloc(sizeof(char), (i + j + 100))))
        return (NULL);
    i = 0;
    j = 0;
    printf("s1 = %s\n", s1);
    while (s1[i])
    {
        result[i] = s1[i];
        i++;
    }
    free((void*)s1);
    while (s2[j] && j < r)
    {
        result[i + j] = s2[j];
        j++;
    }
    //printf("strlen(result) : %zu\n", ft_strlen(result));
    printf("join : %s\n", result);
    return (result);
}
char    *ft_strdup(const char *s1)
{
    char    *result;
    int     i;
    i = 0;
    while (s1[i])
        i++;
    if (!(result = ft_calloc(sizeof(char), (i + 1))))
        return (NULL);
    i = 0;
    while (s1[i])
    {
        result[i] = s1[i];
        i++;
    }
    return (result);
}
char    *ft_result(char *result)
{
    int     i;
    char    *ret;
    
    i = 0;
    while (result[i] != '\n' && result[i])
        i++;
    if (!(ret = ft_calloc(sizeof(char), (i + 1))))
        return (0);
    i = 0;
    while (result[i] != '\n' && result[i])
    {
        ret[i] = result[i];
        i++;
    }
    //printf("result : %s\n", result);
    //printf("ft_result : %s\n", ret);
    return (ret);
}
                                                                                                                                                                                                                                                                                      
int     is_n(char *buff)
{
    int     i;
    i = 0;
    while (buff[i])
    {
        if (buff[i] == '\n')
            return (i);
        i++;
    }
    return (-1);
}
char    *ft_next(char *ret, int r)
{
    int     i;
    int     j;
    char    *result;
    j = is_n(ret);
    i = 0;
    if (j != -1)
        i = j + 1;
    j = ft_strlen(&ret[i]);
    if (!(result = ft_calloc(sizeof(char), (j + 1))))
        return (NULL);
    j = 0;
    if (r == 0 && is_n(ret) == -1)
    {
        result[0] = '\0';
        return (&result[0]);
    }
    while (ret[j + i])
    {
        result[j] = ret[j + i];
        j++;
    }
    free(ret);
    //printf("ft_next : %s\n", result);
    return (&result[0]);
}