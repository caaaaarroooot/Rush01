/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minjuki3 <minjuki3@student.42gyeongsa      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/20 17:02:34 by minjuki3          #+#    #+#             */
/*   Updated: 2024/08/21 01:58:35 by minjuki3         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
#define SIZE 9

void	print_board(const char board[SIZE][SIZE]);
int		is_valid(char board[SIZE][SIZE], int row, int col, int num,
			int input[SIZE][SIZE]);

void	dfs(char board[SIZE][SIZE], int row, int col, int input[SIZE][SIZE])
{
	int	num;
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
		dfs(board, next_row, next_col, input);
		return ;
	}
	num = 0;
	while (++num <= SIZE)
	{
		if (is_valid(board, row, col, num, input))
		{
			board[row][col] = num + '0';
			dfs(board, next_row, next_col, input);
			board[row][col] = '0';
		}
	}
}

int	is_valid(char board[SIZE][SIZE], int row, int col, int num,
		int input[SIZE][SIZE])
{
	int	i;
	int	max;
	int	cnt;

	i = 0;
	while (i < SIZE)
	{
		if (board[row][i] == (num + '0') || board[i][col] == (num + '0'))
		{
			return (0);
		}
		i++;
	}
	i = 0;
	max = 0;
	cnt = 0;
	board[row][col] = num + '0';
	while (i < SIZE) // l ->r
	{
		if (board[row][i] > max)
		{
			max = board[row][i];
			cnt++;
		}
		i++;
	}
	if (((col != SIZE - 1) && (cnt > input[2][row])) || ((col == SIZE - 1)
			&& (cnt != input[2][row])))
	{
		board[row][col] = '0';
		return (0);
	}
	i = 0;
	max = 0;
	cnt = 0;
	while (i < SIZE) // t ->b
	{
		if (board[i][col] > max)
		{
			max = board[i][col];
			cnt++;
		}
		i++;
	}
	if (((row != SIZE - 1) && (cnt > input[0][col])) || ((row == SIZE - 1)
			&& (cnt != input[0][col])))
	{
		board[row][col] = '0';
		return (0);
	}
	if (col == SIZE - 1)
	{
		i = SIZE - 1;
		max = 0;
		cnt = 0;
		while (i >= 0) // r->l
		{
			if (board[row][i] > max)
			{
				max = board[row][i];
				cnt++;
			}
			i--;
		}
		if (cnt != input[3][row])
		{
			board[row][col] = '0';
			return (0);
		}
	}
	if (row == SIZE - 1)
	{
		i = SIZE - 1;
		max = 0;
		cnt = 0;
		while (i >= 0) // b ->t
		{
			if (board[i][col] > max)
			{
				max = board[i][col];
				cnt++;
			}
			i--;
		}
		if (cnt != input[1][col])
		{
			board[row][col] = '0';
			return (0);
		}
	}
	board[row][col] = '0';
	return (1);
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
}

int	main(void)
{
	int	input[4][SIZE] = {
	{1, 2, 6, 3, 2, 4, 3, 2, 3}, 
	{4, 2, 2, 2, 3, 3, 3, 4, 1}, 
	{1, 4, 2, 3, 5, 2, 4, 2, 4}, 
	{4, 2, 3, 2, 3, 2, 3, 6, 1}};

	char board[SIZE][SIZE] = {{'0', '0', '0', '0', '0', '0', '2', '0', '6'},
		{'0', '0', '0', '0', '1', '0', '0', '0', '0'}, {'0', '0', '0', '0', '0',
		'3', '0', '8', '5'}, {'0', '0', '1', '0', '0', '0', '7', '4', '0'},
		{'0', '0', '7', '0', '0', '0', '9', '0', '0'}, {'0', '0', '2', '3', '0',
		'0', '0', '0', '0'}, {'4', '6', '0', '0', '0', '5', '0', '0', '2'},
		{'0', '4', '0', '6', '0', '0', '0', '2', '0'}, {'0', '0', '0', '0', '6',
		'1', '0', '0', '0'}
	};
	dfs(board, 0, 0, input);
	return (0);
}
