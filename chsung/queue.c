/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   queue.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chsung <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/20 16:49:18 by chsung            #+#    #+#             */
/*   Updated: 2024/08/20 16:49:20 by chsung           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "queue.h"

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
			n->borad[i][j] = 0;
		}
	}
}

t_queue	*new_queue(void)
{
	t_queue	*q;

	q = (t_queue *)malloc(sizeof(t_queue));
	q->first = NULL;
	q->last = NULL;
	q->len = 0;
	return (q);
}

void	q_put(t_queue *q, t_node *n)
{
	t_node	*last;

	last = q->last;
	last->next = n;
	n->prev = last;
	q->last = n;
	(q->len)++;
}

t_node	*q_get(t_queue *q)
{
	t_node	*n;

	n = q->first;
	q->first = n->next;
	q->first->prev = NULL;
	n->next = NULL;
	(q->len)--;
	return (n);
}
