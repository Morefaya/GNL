/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcazako <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/27 13:39:32 by jcazako           #+#    #+#             */
/*   Updated: 2016/01/27 15:31:07 by jcazako          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static t_gnl	*rd_list(t_list **list, const int fd)
{
	t_gnl	*content;
	t_list	*lst_tmp;

	if (fd < 0 || !list)
		return (NULL);
	lst_tmp = *list;
	while (lst_tmp)
	{
		if (lst_tmp->content->fd == fd)
			return (lst_tmp->content);
		lst_tmp = lst_tmp->next;
	}
	data->fd = fd;
	if (!(content->str = ft_strnew(BUFF_SIZE)))
		return (NULL);
	if (!(lst_temp = ft_lstnew(content, sizeof(*content))))
	{
		free(data->str);
		return (NULL);
	}
	ft_lstadd(list, lst_temp);
	return ((*list)->content)
}



static int	rd_content(t_gnl *content, char **line)
{
	char	buff[BUFF_SIZE + 1];
	int		len;
	int		ret;

	len = ft_strlen(content->str);
	while (!ft_strchr(content->str, '\n'))
	{
		ft_bzero(buff, BUFF_SIZE + 1);
		if ((ret = read(fd, buff, BUFF_SIZE)) == -1)
			return (-1);
		len += ret;
		if (!ret)
			return ();

	}
}

int		get_next_line(const int fd, char **line)
{
	static	t_list	*list;
	char	buff[BUFF_SIZE + 1];
	int		ret;
	t_gnl	*gnl_data;

	if (!line || !(gnl_data = rd_list(&list, fd)))
		return (-1);
}
