/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_example2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnard <tnard@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/08 21:17:31 by tnard             #+#    #+#             */
/*   Updated: 2022/04/08 21:23:25 by tnard            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/ft_free.h"

int	main(void)
{
	t_m_free	*m_free;
	char		*test;

	m_free = ft_free_init();
	test = ft_free_malloc(m_free, sizeof(char) * 100);
	test[0] = 'a';
	test[1] = 'b';
	test[2] = 'c';
	test[3] = '\0';
	printf("%s\n", test);
	ft_free(m_free);
	return (0);
}
