/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmovchan <mmovchan@student.your42network>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 14:12:50 by mmovchan          #+#    #+#             */
/*   Updated: 2024/10/22 14:12:52 by mmovchan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stddef.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <fcntl.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 10
# endif

int		ft_nl(char *str);
size_t	ft_strlen(const char *str);
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_join_free(char *rem, char *buff);
char	*ft_strcpy(char *dest, char *src);
char	*ft_init_remainder(void);
char	*ft_remainder(int fd, char *remainder);
char	*ft_newline(char *remainder);
char	*ft_afternewline(char *remainder);
char	*get_next_line(int fd);

#endif
