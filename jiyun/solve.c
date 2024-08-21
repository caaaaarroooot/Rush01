/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jilee2 <devcarrot12@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/20 16:44:56 by jilee2            #+#    #+#             */
/*   Updated: 2024/08/21 13:32:29 by jilee2           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "solve.h"
#include "recur.h"
#include "utils.h"
#include <stdlib.h>
#include <stdio.h>
/*
condition[0]: colup
condition[1]: coldown
condition[2]: rowleft
condition[3]: rowright
*/
char	**solve(int size, char **condition)
{
	char	**board;

	printf("solve\n");
	board = initial_board(size, board_malloc(size));
	print_board(size, board);
	printf("go recur\n");
	recur_board(condition, board, 0, size);
	return (board);
}

char	**initial_board(int size, char **board)
{
	int	i;
	int	j;

	printf("initial_board\n");
	i = 0;
	while (i < size)
	{
		j = 0;
		while (j < size)
		{
			board[i][j] = '0';
			j++;
		}
		i++;
	}
	return (board);
}

char	**board_malloc(int n)
{
	char	**board;
	int		i;

	printf("boardmalloc\n");
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

void	board_free(char **board, char **condition)
{
	int	i;

	i = 0;
	while (condition[i] || board[i])
	{
		if (condition[i])
			free (condition[i]);
		if (board[i])
			free (board[i]);
		i++;
	}
	free (condition);
	free (board);
}
