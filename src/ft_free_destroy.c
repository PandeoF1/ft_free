/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnard <tnard@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/08 16:55:05 by tnard             #+#    #+#             */
/*   Updated: 2023/11/01 22:36:10 by tnard            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_free.h"

t_m_free	*g_ft_free;

void	ft_free_destroy(t_m_free *m_free)
{
	t_free	*tmp;

	while (m_free->list)
	{
		tmp = m_free->list;
		m_free->list = m_free->list->next;
		if (tmp->ptr)
			free(tmp->ptr);
		free(tmp);
	}
	free(m_free);
}

__attribute__((constructor)) void	_ft_free_init(void)
{
	g_ft_free = ft_free_init();
}

__attribute__((destructor)) void	_ft_free_destroy(void)
{
	ft_free_destroy(g_ft_free);
}
