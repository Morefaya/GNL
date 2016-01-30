/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcazako <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/21 16:53:05 by jcazako           #+#    #+#             */
/*   Updated: 2016/01/30 18:44:45 by jcazako          ###   ########.fr       */
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
	int		ret;

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
	ret = 0;
	while ((ret = get_next_line(fd, &line)) != -1)
	{
		ft_putendl(line);
	}
	free(line);
	close(fd);
	return (0);
}
