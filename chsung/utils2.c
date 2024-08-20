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

int	is_invalid_row_col_wise(const t_node *n)
{
	int				i;
	int				j;
	int				k;
	t_coordinate	coord;

	coord = get_coordinate(n->depth);
	i = coord.i;
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
	j = coord.j;
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
