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

int	is_invaild_row_left(const t_node *n, t_coordinate c)
{
	int	j;
	int	count;
	int	prev;
	int	con;

	j = -1;
	count = 0;
	prev = 0;
	con = n->constrains[2 * MAX_SIZE + c.i] - '0';
	if (too_fast(con, n->board[c.i][c.j], c.j))
		return (1);
	while (++j < MAX_SIZE)
	{
		if (n->board[c.i][j] == 0)
			break ;
		if (prev < n->board[c.i][j])
		{
			prev = n->board[c.i][j];
			count++;
		}
	}
	if ((count > con) || ((prev == '0' + MAX_SIZE) && (count < con)))
		return (1);
	return (0);
}

int	is_invaild_row_right(const t_node *n, t_coordinate c)
{
	int	j;
	int	count;
	int	prev;
	int	con;

	j = MAX_SIZE;
	count = 0;
	prev = 0;
	con = n->constrains[3 * MAX_SIZE + c.i] - '0';
	if (too_fast_right(con, n->board[c.i][c.j], c.j))
		return (1);
	while (--j >= 0)
	{
		if (n->board[c.i][j] == 0)
			break ;
		if (prev < n->board[c.i][j])
		{
			prev = n->board[c.i][j];
			count++;
		}
	}
	if ((count > con) || ((prev == '0' + MAX_SIZE) && (count < con)))
		return (1);
	return (0);
}

int	is_invaild_col_up(const t_node *n, t_coordinate c)
{
	int	i;
	int	count;
	int	prev;
	int	con;

	i = -1;
	count = 0;
	prev = 0;
	con = n->constrains[c.j] - '0';
	if (too_fast(con, n->board[c.i][c.j], c.i))
		return (1);
	while (++i < MAX_SIZE)
	{
		if (n->board[i][c.j] == 0)
			break ;
		if (prev < n->board[i][c.j])
		{
			prev = n->board[i][c.j];
			count++;
		}
	}
	if ((count > con) || ((prev == '0' + MAX_SIZE) && (count < con)))
		return (1);
	return (0);
}

int	is_invaild_col_down(const t_node *n, t_coordinate c)
{
	int	i;
	int	count;
	int	prev;
	int	con;

	i = MAX_SIZE;
	count = 0;
	prev = 0;
	con = n->constrains[MAX_SIZE + c.j] - '0';
	if (too_fast_right(con, n->board[c.i][c.j], c.i))
		return (1);
	while (--i >= 0)
	{
		if (n->board[i][c.j] == 0)
			break ;
		if (prev < n->board[i][c.j])
		{
			prev = n->board[i][c.j];
			count++;
		}
	}
	if ((count > con) || ((prev == '0' + MAX_SIZE) && (count < con)))
		return (1);
	return (0);
}

int	is_invalid_placement(t_node *n, t_coordinate c)
{
	return (is_duplicate_row(n, c) || is_duplicate_col(n, c) \
		|| is_invaild_col_up(n, c) || is_invaild_col_down (n, c) \
		|| is_invaild_row_left(n, c) || is_invaild_row_right(n, c));
}
