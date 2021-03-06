/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lode-spi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/21 23:08:34 by lode-spi          #+#    #+#             */
/*   Updated: 2018/10/15 18:57:28 by lode-spi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int			main(int argc, char **argv)
{
	int		fd;
	char	*line;
	int		ret;

	if (argc != 2)
		return (1);
	fd = open(argv[1], O_RDONLY);
	while ((ret = get_next_line(fd, &line)) > 0)
	{
		ft_putstr("return : ");
		ft_putnbr(ret);
		ft_putstr(" \"");
		ft_putstr(line);
		ft_putstr("\"\n");
		ft_strdel(&line);
	}
	ft_strdel(&line);
	return (0);
}
