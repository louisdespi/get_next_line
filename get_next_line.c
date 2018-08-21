/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lode-spi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/20 14:05:14 by lode-spi          #+#    #+#             */
/*   Updated: 2018/07/22 00:42:21 by lode-spi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static t_filesaved	*get_file(const int fd, t_list **list)
{
	t_list		*curr;
	t_filesaved	*elt;

	curr = *list;
	while (curr)
	{
		if (((t_filesaved*)curr->content)->fd == fd)
			return (((t_filesaved*)curr->content));
		curr = curr->next;
	}
	if (!(elt = (t_filesaved*)malloc(sizeof(*elt))))
		return (NULL);
	elt->fd = fd;
	elt->remaining = NULL;
	if (!(curr = ft_lstnew(elt, sizeof(*elt))))
		return (NULL);
	ft_lstadd(list, curr);
	return (((t_filesaved*)curr->content));
}

static char			*update_file_state(t_filesaved *curr)
{
	char	*nwl;
	char	*tmp;

	tmp = NULL;
	if (curr->remaining && !(tmp = ft_strdup(curr->remaining)))
		return (NULL);
	if (tmp && (nwl = ft_strchr(tmp, '\n')))
	{
		tmp = ft_strsub(tmp, 0, nwl - tmp);
		ft_strdel(&(curr->remaining));
		curr->remaining = ft_strdup(nwl + 1);
		return (tmp);
	}
	return (NULL);
}

static char			*strforcecat(char **s1, const char *s2)
{
	if (!(*s1))
		return (ft_strdup(s2));
	else
		return (ft_strjoin(*s1, s2));
	ft_strdel(s1);
}

int					get_next_line(const int fd, char **line)
{
	char			buf[BUFF_SIZE + 1];
	int				read_bytes;
	static t_list	*list = NULL;
	t_filesaved		*curr;

	if (!line || fd < 0 || !(curr = get_file(fd, &list)))
		return (-1);
	if ((*line = update_file_state(curr)))
		return (1);
	while ((read_bytes = read(fd, buf, BUFF_SIZE)))
	{
		if (read_bytes < 0)
			return (-1);
		buf[read_bytes] = '\0';
		curr->remaining = strforcecat(&(curr->remaining), buf);
		if ((*line = update_file_state(curr)))
			return (1);
	}
	if (curr->remaining && *(curr->remaining))
	{
		*line = ft_strdup(curr->remaining);
		ft_strdel(&(curr->remaining));
		return (1);
	}
	return (0);
}
