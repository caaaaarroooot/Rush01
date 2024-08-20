/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minjuki3 <minjuki3@student.42gyeongsa      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/20 17:02:34 by minjuki3          #+#    #+#             */
/*   Updated: 2024/08/20 18:58:55 by minjuki3         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>

#define SIZE 4

void	print_board(const char board[SIZE][SIZE]);

void	dfs(char board[SIZE][SIZE], int row, int col)
{
	int	num;
	int	i;
	int	is_exist;
	int	next_row;
	int	next_col;

	if (row == SIZE)
	{
		print_board(board);
		return ;
	}
	next_row = row;
	next_col = col + 1;
	if (next_col == SIZE)
	{
		next_row++;
		next_col = 0;
	}
	if (board[row][col] != '0')
	{
		dfs(board, next_row, next_col);
		return ;
	}
	num = 0;
	while (++num <= 4)
	{
		i = 0;
		is_exist = 0;
		while (i < SIZE)
		{
			if (board[row][i] == num || board[i][col] == num)
			{
				is_exist = 1;
				break ;
			}
			i++;
		}
		if (is_exist)
			continue ;
		board[row][col] = num + '0';
		dfs(board, next_row, next_col);
		board[row][col] = '0';
	}
}

void	print_board(const char board[SIZE][SIZE])
{
	int	i;
	int	j;

	i = 0;
	while (i < SIZE)
	{
		j = 0;
		while (j < SIZE)
		{
			write(1, &board[i][j], 1);
			if (j < SIZE - 1)
				write(1, " ", 1);
			j++;
		}
		write(1, "\n", 1);
		i++;
	}
	write(1, "\n", 1);
}

int	main(void)
{
	char	board[SIZE][SIZE] = {{'0', '0', '4', '0'}, {'0', '4', '0', '0'},
			{'0', '0', '0', '4'}, {'4', '0', '0', '0'}};

	dfs(board, 0, 0);
	return (0);
}
