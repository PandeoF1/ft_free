/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_get_size.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnard <tnard@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/08 18:51:31 by tnard             #+#    #+#             */
/*   Updated: 2022/04/08 19:07:29 by tnard            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_free.h"

unsigned long	ft_free_get_size(t_m_free *m_free)
{
	t_free			*tmp;
	unsigned long	i;

	i = 0;
	tmp = m_free->list;
	if (!tmp)
		return (0);
	while (tmp)
	{
		tmp = tmp->next;
		i += sizeof(tmp->ptr);
	}
	return (i);
}
