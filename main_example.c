/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_example.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnard <tnard@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/08 18:57:57 by tnard             #+#    #+#             */
/*   Updated: 2022/04/08 19:44:37 by tnard            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_free.h"

int	main(void)
{
	t_m_free	*m_free;
	char		*a;
	int			*b;
	char		**c;
	int			x;

	x = 0;
	m_free = ft_free_init();
	while (x < 1000)
	{
		a = malloc(sizeof(char) * 100);
		ft_free_add(m_free, a);
		b = malloc(sizeof(int) * 100);
		ft_free_add(m_free, b);
		c = malloc(sizeof(char *) * 2);
		ft_free_add(m_free, c[1]);
		ft_free_add(m_free, c);
		ft_free_add(m_free, c[0]);
		x++;
	}
	printf("%d\n", ft_free_get_nb(m_free));
	printf("%lu\n", ft_free_get_size(m_free));
	ft_free(m_free);
	return (0);
}
