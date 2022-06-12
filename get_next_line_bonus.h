/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jv <jv@student.42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/11 15:56:39 by jv                #+#    #+#             */
/*   Updated: 2022/06/12 11:27:20 by jv               ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H

# define GET_NEXT_LINE_BONUS_H
# define MAX_FD 100 
# include <unistd.h>
# include <stdlib.h>

void	*ft_calloc(size_t COUNT, size_t ELTSIZE);
char	*get_next_line(int fd);
char	*ft_strchr(const char *STRING, int C);
size_t	ft_strlen(const char *S);
void	*ft_memset(void *BLOCK, int C, size_t SIZE);
char	*ft_strdup(const char *str);
char	*ft_strjoin(char const *s1, char const *s2);

#endif
