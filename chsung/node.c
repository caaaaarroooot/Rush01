/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   node.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chsung <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/20 18:45:05 by chsung            #+#    #+#             */
/*   Updated: 2024/08/20 18:45:06 by chsung           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "universal.h"

t_node	*new_node(void)
{
	int		i;
	int		j;
	t_node	*n;

	n = (t_node *)malloc(sizeof(t_node));
	i = -1;
	while (++i < MAX_SIZE)
	{
		j = -1;
		while (++j < MAX_SIZE)
		{
			n->board[i][j] = 0;
		}
	}
	return (n);
}

t_node	*cp_node(const t_node *src)
{
	int		i;
	int		j;
	t_node	*n;

	n = (t_node *)malloc(sizeof(t_node));
	i = -1;
	while (++i < MAX_SIZE)
	{
		j = -1;
		while (++j < MAX_SIZE)
		{
			n->board[i][j] = src->board[i][j];
		}
	}
	return (n);
}

void	clear_first(t_node	*n, const int i)
{
	if (i < MAX_SIZE)
		n->board[0][i] = MAX_SIZE;
	else if (i < 2 * MAX_SIZE)
		n->board[MAX_SIZE - 1][i - MAX_SIZE] = MAX_SIZE;
	else if (i < 3 * MAX_SIZE)
		n->board[i - 2 * MAX_SIZE][0] = MAX_SIZE;
	else
		n->board[i - 3 * MAX_SIZE][MAX_SIZE - 1] = MAX_SIZE;
}

void	clear_line(t_node	*n, int i, int j, t_step s)
{
	char	c;

	c = '0';
	while (++c <= '0' + MAX_SIZE)
	{
		n->board[i][j] = c;
		i += s.i_step;
		j += s.j_step;
	}
}

t_node	*make_first_node(const char *constrains)
{
	// TODO: change current decision idx
	int		i;
	int		r;
	int		c;
	t_node	*n;

	i = -1;
	n = new_node();
	while (++i < 4 * MAX_SIZE)
	{
		c = constrains[i] - '0';
		if (c == 1)
			clear_first(n, i);
		else if (c == MAX_SIZE)
		{
			if (i < MAX_SIZE)
				clear_line(n, 0, i, (t_step){1, 0});
			else if (i < 2 * MAX_SIZE)
				clear_line(n, MAX_SIZE - 1, i - MAX_SIZE, (t_step){-1, 0});
			else if (i < 3 * MAX_SIZE)
				clear_line(n, i - 2 * MAX_SIZE, 0, (t_step){0, 1});
			else
				clear_line(n, i - 3 * MAX_SIZE, MAX_SIZE - 1, (t_step){0, -1});
		}
	}
	return (n);
}
