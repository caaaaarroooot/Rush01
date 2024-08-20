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

int	already_placed(t_node *n)
{
	t_coordinate	coord;

	coord = get_coordinate(n->depth);
	if (n->board[coord.i][coord.j] != 0)
		return (1);
	return (0);
}

int	try_place(t_node *n, char c)
{
	t_coordinate	coord;

	coord = get_coordinate(n->depth);
	n->board[coord.i][coord.j] = c;
	if (is_invalid_row_col_wise(n))
	{
		// printf("violate: %c\n", c);
		n->board[coord.i][coord.j] = 0;
		return (0);
	}
	return (1);
}

t_node	*build_result(const t_node *n)
{
	int		i;
	int		j;
	t_node	*res;

	res = malloc(sizeof(t_node));
	res->constrains = n->constrains;
	res->depth = n->depth;
	i = -1;
	while (++i < MAX_SIZE)
	{
		j = -1;
		while (++j < MAX_SIZE)
		{
			res->board[i][j] = n->board[i][j];
		}
	}
	return (res);
}

t_node	*dfs(const t_node *prev)
{
	char			c;
	t_node			*res;
	t_node			current;

	res = NULL;
	new_node(&current, prev);
	// print_str("----------\n");
	// printf("%d\n", current.depth);
	// print_board(&current);
	if (current.depth == MAX_SIZE * MAX_SIZE)
	{
		if (is_not_goal(&current))
			return (NULL);
		return (build_result(&current));
	}
	if (already_placed(&current))
		return (dfs(&current));
	c = '0';
	while (++c <= '0' + MAX_SIZE)
	{
		if (try_place(&current, c))
		{
			// printf("try_place\n");
			res = dfs(&current);
		}
		if (res)
			return (res);
	}
	return (NULL);
}

t_node	*solve(const char *constrains)
{
	t_node	node;

	node.depth = -1;
	node.constrains = constrains;
	init_node(&node);
	return (dfs(&node));
}
