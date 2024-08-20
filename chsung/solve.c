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

#include "solve.h"

int	view_row(const t_node *n, const char *constrains, const int ith,
				const int from_left)
{
	int			i;
	int			j;
	int			step;

	i = ith;
	if (from_left)
	{
		j = 0;
		step = 1;
	}
	else
	{
		j = MAX_SIZE - 1;
		step = -1;
	}
	return (0);
}

/*int		is_violate(t_node *n, const char *constrains)
{

}*/

char	**solve(const char *constrains)
{
	int		i;
	char	**board;

	board = malloc(sizeof(char *) * MAX_SIZE);
	i = -1;
	while (++i < MAX_SIZE)
		board[i] = malloc(sizeof(char) * MAX_SIZE);
}
