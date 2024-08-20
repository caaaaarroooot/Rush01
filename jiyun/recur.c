/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   recur.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jilee2 <devcarrot12@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/20 17:35:56 by jilee2            #+#    #+#             */
/*   Updated: 2024/08/21 06:23:58 by jilee2           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "recur.h"
#include "utils.h"
#include <stdio.h>
#include <stdlib.h>
void	recur_board(char **condition, char **board, int n, int size)
{
	int	i;
	int	c;
	int	r;
	
	
	i = 1;
	c = n / size;
	r = n % size;
//	printf("n: %d, size: %d, c: %d, r: %d\n", n, size, c, r);
	while (i <= size)
	{
		board[c][r] = i + '0';
//		print_board(size, board);
//		printf("next\n\n");
		if (recur_possible (condition, board, n, size) == 1 && n == size * size -1)
		{
			print_board(size, board);
			exit(0);
			return ;
		} 
		else if (recur_possible (condition, board, n, size) == 1)
		{
//			printf("n: %d\n", n);
			recur_board(condition, board, n + 1, size);
		}
		else if (recur_possible (condition, board, n, size) == 0 &&
			       n == size * size -1 && i == size)
		{
			print_str("??Error!\n");
			return ;
		}
		i++;
	}
}

int	recur_possible(char **condition, char **board, int n, int size)
{
	if (check_row(board, n, size) == 1 && check_col(board, n, size) == 1 &&
		check_u(condition, board, n, size) == 1 && check_l(condition, board, n, size) == 1 &&
		check_d(condition, board, n, size) == 1 && check_r(condition, board, n, size) == 1)
	{
//		printf("good\n");
		return (1);
	}
	return (0);
}

int	check_row(char **board, int n, int size)
{
	int	i;
	int c = n / size;
	int r = n % size;

	i = 0;
	while (i < r)
	{
//		printf("board[%d][%d]:%d, 1 board[%d][%d]: %d\n", c, r, board[c][r]-48, c, i, board[c][i]-48);
		if (board[c][r] == board[c][i]){
			return (0);
		}
		i++;
	}
//	printf("row is good\n");
	return (1);
}

int	check_col(char **board, int n, int size)
{
	int	i;
	int c = n / size;
	int r = n % size;

	i = 0;
	while (i < c)
	{
		if (board[c][r] == board[i][r])
			return (0);
		i++;
	}
//	printf("col is good\n");
	return (1);
}
/*
   여기서부터 조금 까다로움
   1. 수가 n이냐?
   	1-1. 오름차순의 개수 완성 됐는가?
   2. 수가 n이 아니냐?
   	2-1. 오름차순의 개수 완성 됐는가?
   각 방향에 대하여!
 */
int	check_u(char **condition, char **board, int n, int size)
{
	int	i;
	int	cnt;
	int	num;
	int	c;
	int	r;

	c = n / size;
	r = n % size;
	i = 0;
	cnt = 0;
	num = board[0][r];
	while (board[i][r] != size && board[i][r] != '0' && i < size - 1)
	{
		if (num < board[i+1][r])
		{
			cnt++;
			num = board[i+1][r];
		}
		i++;
	}
	if (cnt > condition[0][r] - 49 || (cnt < condition[0][r] - 49 && c == size -1)) 
		return (0);
//	printf("up is good\n");
	return (1);
}

int	check_l(char **condition, char **board, int n, int size)
{
	int	i;
	int	cnt;
	int	num;
	int	c;
	int	r;

	c = n / size;
	r = n % size;
	i = 0;
	cnt = 0;
	num = board[c][0];
	while (board[c][i] != size && board[c][i] != '0' && i < size - 1)
	{
		if (num < board[c][i + 1])
		{
//			printf("num: %d, board[%d][%d]: %d\n", num, c, i+1, board[c][i+1]);
			cnt++;
			num = board[c][i + 1];
		}
		i++;
	}
//	printf("check L: %d, cnt: %d\n", condition[2][c] - 49, cnt);
	if (cnt > condition[2][c] - 49 || (cnt < condition[2][c] - 49 && r == size -1))
		return (0);
//	printf("left is good\n");
	return (1);
}

int	check_d(char **condition, char **board, int n, int size)
{
	int	i;
	int	cnt;
	int	num;
	int	r;

	r = n % size;
	num = board[size - 1][r];
	cnt = n / size;
	if (cnt == size -1)
	{
//		printf("down! here we go\n");
		cnt = 0;
		i = size - 1;
//		printf("before whlie: board[%d][%d] : %d, size: %d\n", i, r, board[i][r], size);
		while (board[i][r] - '0' != size)
		{
//			printf("i: %d, num: %d, board[%d][%d]: %d\n", i, num, i-1, r, board[i-1][r]);
			if (num < board[i-1][r])
			{
//				printf("num: %d, board[%d][%d]: %d\n", num, i -1, r, board[i-1][r]);
				cnt++;
				num = board[i-1][r];
			}
			i--;
		}
//		printf("%d, cnt: %d\n", condition[1][r] - 1, cnt);
		if ((condition[1][r] - 49) != cnt)
			return (0);
	}
//	printf("down is good\n");
	return (1);
}

int	check_r(char **condition, char **board, int n, int size)
{
	int	i;
	int	cnt;
	int	num;
	int	c;

	c = n / size;
	num = board[c][size - 1];
	cnt = n % size;
	if (cnt == size -1)
	{
//		printf("here we go\n");
		cnt = 0;
		i = size - 1;
		while (board[c][i] != size && i >= 0)
		{
//			printf("i: %d\n", i);
			if (num < board[c][i - 1])
			{
//				printf("num: %d, board[%d][%d]: %d\n", num, c, i -1, board[c][i-1]);
				cnt++;
				num = board[c][i - 1];
			}
			i--;
		}
//		printf("%d, cnt: %d\n", condition[3][c] - 1, cnt);
		if ((condition[3][c] - 49) != cnt)
			return (0);
	}
//	printf("right is good\n");
	return (1);
}
