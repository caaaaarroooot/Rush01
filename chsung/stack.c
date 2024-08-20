/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chsung <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/20 16:49:18 by chsung            #+#    #+#             */
/*   Updated: 2024/08/20 16:49:20 by chsung           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"

t_node	*new_node(void)
{
	int		i;
	int		j;
	t_node	*n;

	n = (t_node *)malloc(sizeof(t_node));
	n->prev = NULL;
	n->next = NULL;
	i = -1;
	j = -1;
	while (++i < MAX_SIZE)
	{
		while (++j < MAX_SIZE)
		{
			n->board[i][j] = 0;
		}
	}
	return (n);
}

t_stack	*new_stack(void)
{
	t_stack	*s;

	s = (t_stack *)malloc(sizeof(t_stack));
	s->first = NULL;
	s->last = NULL;
	s->len = 0;
	return (s);
}

void	s_put(t_stack *s, t_node *n)
{
	t_node	*last;

	last = s->last;
	last->next = n;
	n->prev = last;
	s->last = n;
	(s->len)++;
}

t_node	*s_pop(t_stack *s)
{
	t_node	*n;

	n = s->last;
	s->last = n->prev;
	s->last->next = NULL;
	n->prev = NULL;
	(s->len)--;
	return (n);
}
