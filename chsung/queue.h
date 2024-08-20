/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   queue.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chsung <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/20 16:49:14 by chsung            #+#    #+#             */
/*   Updated: 2024/08/20 16:49:15 by chsung           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef QUEUE_H
# define QUEUE_H
# include "utils.h"

typedef struct s_node
{
	t_node	*prev;
	t_node	*next;
	char	borad[MAX_SIZE][MAX_SIZE];
}	t_node;

typedef struct s_queue
{
	struct s_node	*first;
	struct s_node	*last;
	unsigned int	len;
}	t_queue;

t_queue	*new_queue(void);
void	q_put(t_queue *q, t_node *n);
t_node	*q_get(t_queue *q);
#endif
