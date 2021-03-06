/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lode-spi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/06 08:43:31 by lode-spi          #+#    #+#             */
/*   Updated: 2018/10/12 16:26:17 by lode-spi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# define BUFF_SIZE 32
# include "libft.h"
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <unistd.h>

# define ERROR -1
# define END_OF_FILE 0
# define SUCCESS 1

typedef struct	s_filesaved
{
	int		fd;
	char	*remaining;
}				t_filesaved;

int				get_next_line(const int fd, char **line);

#endif
