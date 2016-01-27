/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcazako <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/27 13:41:06 by jcazako           #+#    #+#             */
/*   Updated: 2016/01/27 13:46:24 by jcazako          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include "libft.h"

# define BUFF_SIZE 1

typedef struct	s_gnl
{
	int			fd;
	char		*str;
}				t_gnl;

int	get_next_line(const int fd, char **line);

#endif
