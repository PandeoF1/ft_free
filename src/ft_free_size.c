/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_size.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnard <tnard@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/08 18:51:31 by tnard             #+#    #+#             */
/*   Updated: 2022/04/09 20:42:20 by tnard            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_free.h"

int	ft_free_size(t_m_free *m_free)
{
	t_free	*tmp;
	int		i;

	i = 0;
	tmp = m_free->list;
	if (tmp)
		i = 1;
	if (!tmp)
		return (i);
	while (tmp->next)
	{
		tmp = tmp->next;
		i++;
	}
	return (i);
}
