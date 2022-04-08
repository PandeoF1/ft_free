/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_remove.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnard <tnard@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/08 16:54:39 by tnard             #+#    #+#             */
/*   Updated: 2022/04/08 16:54:45 by tnard            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_free.h"

void	ft_free_remove_if(t_free **begin_list, void *ptr_ref)
{
	t_free	*to_free;

	if (*begin_list)
	{
		if ((*begin_list)->ptr == ptr_ref)
		{
			to_free = *begin_list;
			*begin_list = (*begin_list)->next;
			if (to_free->ptr)
				free(to_free->ptr);
			free(to_free);
			ft_free_remove_if(begin_list, ptr_ref);
		}
		else
			ft_free_remove_if(&(*begin_list)->next, ptr_ref);
	}
}

void	ft_free_remove(t_m_free *m_free, void *ptr)
{
	ft_free_remove_if(&m_free->list, ptr);
}
