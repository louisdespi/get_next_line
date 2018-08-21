/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lode-spi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/21 23:08:34 by lode-spi          #+#    #+#             */
/*   Updated: 2018/07/24 00:57:11 by lode-spi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int			main(int argc, char **argv)
{
	int		fd;
	char	*line;
	int		i;
	int		j;

	if (argc != 2)
		return (1);
	if ((fd = open(argv[1], O_RDONLY)) < 0)
	{
		ft_putendl("Error while opening file");
		return (1);
	}
	ft_putstr("file successfully opened. fd = ");
	ft_putnbr(fd);
	ft_putchar('\n');
	i = 0;
	while ((j = get_next_line(0, &line)) > 0)
	{
		ft_putstr("return : ");
		ft_putnbr(j);
		ft_putchar('\n');
		ft_putnbr(i);
		ft_putstr(" : ");
		ft_putendl(line);
		i++;
	}
	return (0);
}
