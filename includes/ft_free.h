/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnard <tnard@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/08 15:35:03 by tnard             #+#    #+#             */
/*   Updated: 2023/11/01 21:25:51 by tnard            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_FREE_H
# define FT_FREE_H

# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>

typedef struct s_free
{
	void			*ptr;
	struct s_free	*next;
}				t_free;

typedef struct s_m_free
{
	struct s_free	*list;
}				t_m_free;

t_m_free		*ft_free_init(void);

void			ft_free(t_m_free *m_free);

void			*ft_malloc(size_t size);
void			*ft_xmalloc(size_t size);

void			ft_free_remove(void *ptr);
void			ft_free_remove_if(t_free **begin_list, void *ptr_ref);

int				ft_free_add(void *ptr);
int				ft_free_add_value(t_free *new, t_free *tmp);

int				ft_free_size(void);

extern t_m_free	*g_ft_free;

#endif