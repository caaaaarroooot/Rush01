/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jilee2 <devcarrot12@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/20 17:35:56 by jilee2            #+#    #+#             */
/*   Updated: 2024/08/21 13:58:52 by jilee2           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "universal.h"

int	is_invaild_row_left(const t_node *n, const int i)
{
	int	j;
	int	c;
	int	prev;
	int	constrain;

	j = -1;
	c = 0;
	prev = 0;
	constrain = n->constrains[2 * MAX_SIZE + i] - '0';
	while (++j < MAX_SIZE)
	{
		if (n->board[i][j] == 0)
			break ;
		if (prev < n->board[i][j])
		{
			prev = n->board[i][j];
			c++;
		}
	}
	if ((c > constrain) || ((prev == '0' + MAX_SIZE) && (c < constrain)))
		return (1);
	return (0);
}

int	is_invaild_row_right(const t_node *n, const int i)
{
	int	j;
	int	c;
	int	prev;
	int	constrain;

	j = MAX_SIZE;
	c = 0;
	prev = 0;
	constrain = n->constrains[3 * MAX_SIZE + i] - '0';
	while (--j >= 0)
	{
		if (n->board[i][j] == 0)
			break ;
		if (prev < n->board[i][j])
		{
			prev = n->board[i][j];
			c++;
		}
	}
	if ((c > constrain) || ((prev == '0' + MAX_SIZE) && (c < constrain)))
		return (1);
	return (0);
}

int	is_invaild_col_up(const t_node *n, const int j)
{
	int	i;
	int	c;
	int	prev;
	int	constrain;

	i = -1;
	c = 0;
	prev = 0;
	constrain = n->constrains[j] - '0';
	while (++i < MAX_SIZE)
	{
		if (n->board[i][j] == 0)
			break ;
		if (prev < n->board[i][j])
		{
			prev = n->board[i][j];
			c++;
		}
	}
	if ((c > constrain) || ((prev == '0' + MAX_SIZE) && (c < constrain)))
		return (1);
	return (0);
}

int	is_invaild_col_down(const t_node *n, const int j)
{
	int	i;
	int	c;
	int	prev;
	int	constrain;

	i = MAX_SIZE;
	c = 0;
	prev = 0;
	constrain = n->constrains[MAX_SIZE + j] - '0';
	while (--i >= 0)
	{
		if (n->board[i][j] == 0)
			break ;
		if (prev < n->board[i][j])
		{
			prev = n->board[i][j];
			c++;
		}
	}
	if ((c > constrain) || ((prev == '0' + MAX_SIZE) && (c < constrain)))
		return (1);
	return (0);
}

int	is_invalid_placement(t_node *n, t_coordinate c)
{
	// return (is_duplicate_row(n, c) || is_duplicate_col(n, c));
	// return (is_duplicate_row(n, c) || is_duplicate_col(n, c) \
	// 	|| is_invaild_col_up(n, c.j) || is_invaild_row_left(n, c.i));
	return (is_duplicate_row(n, c) || is_duplicate_col(n, c) \
		|| is_invaild_col_up(n, c.j) || is_invaild_col_down (n, c.j) \
		|| is_invaild_row_left(n, c.i) || is_invaild_row_right(n, c.i));
}
