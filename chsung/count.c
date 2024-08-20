/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   count.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chsung <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/20 17:41:38 by chsung            #+#    #+#             */
/*   Updated: 2024/08/20 17:51:17 by chsung           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "universal.h"

int	count_row_left(const t_node *n, const int i)
{
	int	j;
	int	c;
	int	prev;

	j = -1;
	c = 0;
	prev = 0;
	while (++j < MAX_SIZE)
	{
		if (prev < n->board[i][j])
		{
			prev = n->board[i][j];
			c++;
		}
	}
	return (c);
}

int	count_row_right(const t_node *n, const int i)
{
	int	j;
	int	c;
	int	prev;

	j = MAX_SIZE;
	c = 0;
	prev = 0;
	while (--j >= 0)
	{
		if (prev < n->board[i][j])
		{
			prev = n->board[i][j];
			c++;
		}
	}
	return (c);
}

int	count_col_up(const t_node *n, const int j)
{
	int	i;
	int	c;
	int	prev;

	i = -1;
	c = 0;
	prev = 0;
	while (++i < MAX_SIZE)
	{
		if (prev < n->board[i][j])
		{
			prev = n->board[i][j];
			c++;
		}
	}
	return (c);
}

int	count_col_down(const t_node *n, const int j)
{
	int	i;
	int	c;
	int	prev;

	i = MAX_SIZE;
	c = 0;
	prev = 0;
	while (--i >= 0)
	{
		if (prev < n->board[i][j])
		{
			prev = n->board[i][j];
			c++;
		}
	}
	return (c);
}

int	is_violate(const t_node *n, const int i, const int j, const char *constrains)
{
	int	idx;
	int	c;

	if (count_col_up(n, j) != constrains[j])
		return (1);
	if (count_col_down(n, j) != constrains[MAX_SIZE + j])
		return (1);
	if (count_row_left(n, i) != constrains[2 * MAX_SIZE + i])
		return (1);
	if (count_row_right(n, i) != constrains[3 * MAX_SIZE + i])
		return (1);
	return (0);
}
