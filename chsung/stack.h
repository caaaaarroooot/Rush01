/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chsung <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/20 16:49:14 by chsung            #+#    #+#             */
/*   Updated: 2024/08/20 16:49:15 by chsung           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STACK_H
# define STACK_H
# include "utils.h"

typedef struct s_node
{
	struct s_node	*prev;
	struct s_node	*next;
	char	board[MAX_SIZE][MAX_SIZE];
}	t_node;

typedef struct s_stack
{
	struct s_node	*first;
	struct s_node	*last;
	unsigned int	len;
}	t_stack;

t_node	*new_node(void);
t_stack	*new_queue(void);
void	s_put(t_stack *s, t_node *n);
t_node	*s_get(t_stack *s);
#endif
