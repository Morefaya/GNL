/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcazako <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/21 16:53:05 by jcazako           #+#    #+#             */
/*   Updated: 2016/02/01 20:39:43 by jcazako          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>

#include "get_next_line.h"

static void	puterror(void)
{
	ft_putendl("error");
	exit(1);
}

int			main(int ac, char **av)
{
	int		fd;
	char	*line;
	int	i;

	i = 0;
	line = NULL;
	fd = 0;
	if (ac == 2)
	{
		if ((fd = open(av[1], O_RDONLY)) == -1)
		{
			puterror();
		}
	}
	else if (ac > 2)
		puterror();
	/*while (get_next_line(fd, &line))
	{
		ft_putendl(line);
		free(line);
	}*/
	while (i < 6)
	{
		ft_putnbr(get_next_line(fd, &line));
		ft_putchar('\t');
		ft_putendl(line);
		ft_strdel(&line);
		i++;
	}
	close(fd);
	return (0);
}
