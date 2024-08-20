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

int	is_duplicate_row(const t_node *n)
{
	int	i;
	int	j;
	int	k;

	i = get_coordinate(n->depth).i;
	j = -1;
	while (++j < MAX_SIZE)
	{
		if (n->board[i][j] == 0)
			continue ;
		k = j;
		while (++k < MAX_SIZE)
			if (n->board[i][j] == n->board[i][k])
				return (1);
	}
	return (0);
}

int	is_duplicate_col(const t_node *n)
{
	int	i;
	int	j;
	int	k;

	j = get_coordinate(n->depth).j;
	i = -1;
	while (++i < MAX_SIZE)
	{
		if (n->board[i][j] == 0)
			continue ;
		k = i;
		while (++k < MAX_SIZE)
			if (n->board[i][j] == n->board[k][j])
				return (1);
	}
	return (0);
}
