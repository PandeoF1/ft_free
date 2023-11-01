/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_add.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnard <tnard@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/08 16:54:18 by tnard             #+#    #+#             */
/*   Updated: 2023/11/01 21:09:01 by tnard            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_free.h"

int	ft_free_add_value(t_free *new, t_free *tmp)
{
	if (g_ft_free->list)
	{
		tmp = g_ft_free->list;
		while (tmp->next)
		{
			if (tmp->ptr == new->ptr)
				return (0);
			tmp = tmp->next;
		}
		if (tmp->ptr == new->ptr)
			return (0);
		tmp->next = new;
		return (1);
	}
	else
	{
		g_ft_free->list = new;
		return (1);
	}
	return (0);
}

int	ft_free_add(void *ptr)
{
	t_free	*new;
	t_free	*tmp;

	if (ptr)
	{
		new = (t_free *)malloc(sizeof(t_free));
		tmp = NULL;
		new->ptr = ptr;
		new->next = NULL;
		if (ft_free_add_value(new, tmp))
			return (1);
		else
			free(new);
	}
	return (0);
}
