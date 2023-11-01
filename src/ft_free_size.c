/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_size.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnard <tnard@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/08 18:51:31 by tnard             #+#    #+#             */
/*   Updated: 2023/11/01 21:11:49 by tnard            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_free.h"

int	ft_free_size()
{
	t_free	*tmp;
	int		i;

	i = 0;
	tmp = g_ft_free->list;
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
