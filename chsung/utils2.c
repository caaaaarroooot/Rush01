/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chsung <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/20 21:44:15 by chsung            #+#    #+#             */
/*   Updated: 2024/08/20 21:44:20 by chsung           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "universal.h"

int	is_duplicate_row(const t_node *n, t_coordinate c)
{
	int	k;

	c = get_coordinate(n->depth);
	k = -1;
	while (++k < MAX_SIZE)
	{
		if (k == c.j)
			continue ;
		if (n->board[c.i][c.j] == n->board[c.i][k])
			return (1);
	}
	return (0);
}

int	is_duplicate_col(const t_node *n, t_coordinate c)
{
	int	k;

	c = get_coordinate(n->depth);
	k = -1;
	while (++k < MAX_SIZE)
	{
		if (k == c.i)
			continue ;
		if (n->board[c.i][c.j] == n->board[k][c.j])
			return (1);
	}
	return (0);
}

int	too_fast(int con, char val, int idx)
{
	int	min_idx;

	min_idx = con - 1 - (MAX_SIZE - (val - '0'));
	if (idx < min_idx)
		return (1);
	return (0);
}

int	too_fast_right(int con, char val, int idx)
{
	int	min_idx;
	int	max_idx;

	min_idx = con - 1 - (MAX_SIZE - (val - '0'));
	max_idx = MAX_SIZE - 1 - min_idx;
	if (idx > max_idx)
		return (1);
	return (0);
}
