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

char	*make_available_decision(const t_node *n, int r, int c)
{
	int		i;
	char	*arr;
	t_node	*t;
	
	i = 0;
	arr = malloc(MAX_SIZE + 1);
	while (++i < MAX_SIZE)
	{
		t = cp_node(n);
		// for i in 1 to 4,
		// check if i can place here. if yes, add to arr
		// else, pass
	}
	arr[i] = 0;
	return (arr);
}

int	dfs(const t_node *prev, const int depth)
{
	t_node current;
}

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
