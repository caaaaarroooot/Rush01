/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chsung <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/20 15:24:49 by chsung            #+#    #+#             */
/*   Updated: 2024/08/20 15:24:51 by chsung           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "universal.h"

t_node	*solve(const char *constrains)
{
	int		i;
	t_stack	*s;
	t_node	*answer;

	s = new_stack();
	s_put(s, make_first_node(constrains));
	while (s->len != 0)
	{
		/* code */
	}
	if (s->len == 0)
		return (NULL);
	return (answer);
}
