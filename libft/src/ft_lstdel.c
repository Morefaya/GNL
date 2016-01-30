/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcazako <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/27 10:56:20 by jcazako           #+#    #+#             */
/*   Updated: 2016/01/27 12:21:12 by jcazako          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_listdel(t_list **alst, void (*del)(void*, size_t))
{
	if ((*alst)->next)
		ft_listdel(&(*alst)->next, del);
	ft_lstdelone(alst, del);
}
