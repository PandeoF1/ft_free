/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_example.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnard <tnard@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/08 18:57:57 by tnard             #+#    #+#             */
/*   Updated: 2022/04/08 20:26:14 by tnard            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

/*
	This is a big test with more than 


*/
#include "includes/ft_free.h"

int	main(void)
{
	t_m_free	*m_free;
	char		*a;
	int			*b;
	char		**c;
	char		*d;
	int			x;

	d = NULL;
	x = 0;
	m_free = ft_free_init();
	while (x < 1000)
	{
		a = malloc(sizeof(char) * 100);
		ft_free_add(m_free, a);
		b = malloc(sizeof(int) * 100);
		ft_free_add(m_free, b);
		c = malloc(sizeof(char *) * 2);
		c[0] = malloc(sizeof(char) * 100);
		c[1] = malloc(sizeof(char) * 100);
		ft_free_add(m_free, d); // Exemple of null pointer
		ft_free_add(m_free, c[1]);
		ft_free_add(m_free, c);
		ft_free_add(m_free, c[0]);
		x++;
	}
	printf("%d\n", ft_free_size(m_free));
	ft_free(m_free);
	return (0);
}
