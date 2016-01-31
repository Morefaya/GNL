/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcazako <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/27 13:39:32 by jcazako           #+#    #+#             */
/*   Updated: 2016/01/30 18:41:07 by jcazako          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static t_gnl	*rd_list(t_list **list, const int fd)
{
	t_gnl		content;
	t_list		*lst_tmp;

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

/*static char		*realloc_str(char **str, char *buff, int len)
{
	char		*temp;

	temp = *str;
	if (!(*str = ft_strnew(len)))
		return (NULL);
	if (temp)
	{
		ft_strcpy(*str, temp);
		free(temp);
	}
	ft_strcat(*str, buff);
	return (*str);
}*/

static char			*gnl(char **line, char **str)
{
	int			i;
	char		*str_n;

	if (!*str)
		return (NULL);
	i = 0;
	str_n = NULL;
	while (*(*str + i) != '\n' && *(*str + i) != '\0')
		i++;
	if (!(*line = ft_strsub(*str, 0, i)))
		return (NULL);
	if (*(*str + i) == '\n')
	{
		i++;
		if (!(str_n = ft_strsub(*str, i, ft_strlen(*str) - i)))
			return (NULL);
	}
	ft_strdel(str);
	*str = str_n;
	return (*line);
}

/*static int		rd_content(t_gnl *content, char **line)
{
	char		buff[BUFF_SIZE + 1];
	int			len;
	int			ret;

	len = ft_strlen(content->str);
	while (!ft_strchr(content->str, '\n'))
	{
		ft_bzero(buff, BUFF_SIZE + 1);
		if ((ret = read(content->fd, buff, BUFF_SIZE)) == -1)
			return (-1);
		len += ret;
		if (!ret)
		{
			if (!gnl(line, &(content->str)))
				return (-1);
			return (0);
		}
		if (!realloc_str(&(content->str), buff, len))
			return (-1);
	}
	if (!gnl(line, &(content->str)))
		return (-1);
	return (1);
}*/

static int			read_fd(t_gnl **content)
{
	char	buff[BUFF_SIZE + 1];
	char	*tmp;
	int	ret;

	ft_bzero(buff, BUFF_SIZE + 1);
	while ((ret = read((*content)->fd, buff, BUFF_SIZE)) > 0)
	{
		tmp = (*content)->str;
		if(!((*content)->str = ft_strjoin((*content)->str, buff)))
			return (1);
		ft_bzero(buff, BUFF_SIZE + 1);
		free(tmp);
	}
	if (ret == -1)
		return (1);
	return (0);
}

int				get_next_line(const int fd, char **line)
{
	static t_list	*list;
	t_gnl			*gnl_data;

	if (BUFF_SIZE <= 0 || !line || !(gnl_data = rd_list(&list, fd)))
		return (-1);
	if (read_fd(&gnl_data))
		return (-2);
	if (!gnl(line , &(gnl_data->str)))
		return (-3);
	if (!**line)
		return (0);
	return (1);
}
