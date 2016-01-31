/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcazako <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/27 13:39:32 by jcazako           #+#    #+#             */
/*   Updated: 2016/01/31 17:12:43 by jcazako          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static t_gnl		*rd_list(t_list **list, const int fd)
{
	t_gnl			content;
	t_list			*lst_tmp;

	if (fd < 0 || !list)
		return (NULL);
	lst_tmp = *list;
	while (lst_tmp)
	{
		if (((t_gnl*)(lst_tmp->content))->fd == fd)
			return (lst_tmp->content);
		lst_tmp = lst_tmp->next;
	}
	content.fd = fd;
	if (!(content.str = ft_strnew(BUFF_SIZE)))
		return (NULL);
	if (!(lst_tmp = ft_lstnew(&content, sizeof(content))))
	{
		free(content.str);
		return (NULL);
	}
	ft_lstadd(list, lst_tmp);
	return ((*list)->content);
}

static int			gnl(char **line, char **str)
{
	int				i;
	char			*str_n;

	i = 0;
	str_n = NULL;
	if (*str)
	{
		while (*(*str + i) != '\n' && *(*str + i) != '\0')
			i++;
		if (!(*line = ft_strsub(*str, 0, i)))
			return (-1);
		if (*(*str + i) == '\n')
		{
			i++;
			if (!(str_n = ft_strsub(*str, i, ft_strlen(*str) - i)))
				return (-1);
		}
		ft_strdel(str);
		*str = str_n;
	}
	else if (!(*line = ft_strnew(0)))
		return (-1);
	if (**line)
		return (1);
	return (0);
}

static int			read_fd(t_gnl **content)
{
	char			buff[BUFF_SIZE + 1];
	char			*tmp;
	int				ret;

	ft_bzero(buff, BUFF_SIZE + 1);
	while ((ret = read((*content)->fd, buff, BUFF_SIZE)) > 0)
	{
		tmp = (*content)->str;
		if (!((*content)->str = ft_strjoin((*content)->str, buff)))
			return (1);
		ft_bzero(buff, BUFF_SIZE + 1);
		free(tmp);
	}
	if (ret == -1)
		return (1);
	return (0);
}

int					get_next_line(const int fd, char **line)
{
	static t_list	*list;
	t_gnl			*gnl_data;

	if (BUFF_SIZE <= 0 || !line || !(gnl_data = rd_list(&list, fd)))
		return (-1);
	if (read_fd(&gnl_data))
		return (-1);
	return (gnl(line, &(gnl_data->str)));
}
