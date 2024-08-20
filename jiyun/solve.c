/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jilee2 <devcarrot12@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/20 16:44:56 by jilee2            #+#    #+#             */
/*   Updated: 2024/08/20 18:09:59 by jilee2           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "solve.h"
#include "recur.h"
/*
condition[0]: colup
condition[1]: coldown
condition[2]: rowleft
condition[3]: rowright
*/
char	**solve(int n, char **condition)
{
	char	**board;
	int		i;

	board = initial_board(n, board_malloc(n));
	board = recur_board(condition, board, 0, 4);
	return (board);
}

char	**initial_board(int n, char **condition)
{
	int	i;
	int	j;

	i = 0;
	while (condition[i])
	{
		j = 0;
		while (condition[i][j])
		{
			condition[i][j] = "0";
			j++;
		}
		i++;
	}
}

char	**board_malloc(int n)
{
	char	**board;
	int		i;

	board = (char **)malloc(sizeof(char *) * n);
	if (!board)
		return (0);
	i = 0;
	while (i < n)
	{
		board[i] = (char *)malloc(sizeof(char) * n);
		if (!board[i])
		{
			while (--i >= 0)
				free(board);
			free(board);
			return (0);
		}
		i++;
	}
	return (board);
}
