/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   recur.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jilee2 <devcarrot12@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/20 17:35:56 by jilee2            #+#    #+#             */
/*   Updated: 2024/08/21 13:58:52 by jilee2           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
 	종료조건 작업중
 */

#include "recur.h"
#include "utils.h"
#include <stdio.h>
#include <stdlib.h>
void	recur_board(char **condition, char **board, int n, int size)
{
	int	i;
	int	p;
		
	i = 1;
	printf("condition[size][0]: %d\n", condition[size][0]);
	printf("board[%d][%d]: %d\n", n / size, n % size, board[n/size][n%size]);
//	printf("n: %d, size: %d\n", n, size);
//	모든 경우의 수를 고려한 후 탈출시키지 못해서 segmentation fault 걸리는듯
	while (i <= size)
	{
		board[n / size][n % size] = i + '0';
		p = recur_possible (condition, board, n, size);
//		print_board(size, board);
//		printf("next\n\n");
		if (p == 1 && n == size * size -1)
		{
			print_board(size, board);
			condition[size][0] = 1;
			return ;
		} 
		else if (p == 1 && n < size * size)
		{
//			printf("n: %d\n", n);
			recur_board(condition, board, n + 1, size);
		}
		/*
		else if (p == 0 && n == size * size -1 && i == size)
			return ;*/
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
//	int	c;
//	int	r;

//	c = n / size;
//	r = n % size;
	i = 0;
	cnt = 0;
	num = board[0][n % size];
	while (board[i][n % size] != size && board[i][n % size] != '0' && i < size - 1)
	{
		if (num < board[i+1][n % size])
		{
			cnt++;
			num = board[i+1][n % size];
		}
		i++;
	}
	if (cnt > condition[0][n % size] - 49 || (cnt < condition[0][n % size] - 49 && n / size == size -1)) 
		return (0);
//	printf("up is good\n");
	return (1);
}

int	check_l(char **condition, char **board, int n, int size)
{
	int	i;
	int	cnt;
	int	num;
//	int	c;
//	int	r;

//	c = n / size;
//	r = n % size;
	i = 0;
	cnt = 0;
	num = board[n / size][0];
	while (board[n / size][i] != size && board[n / size][i] != '0' && i < size - 1)
	{
		if (num < board[n / size][i + 1])
		{
//			printf("num: %d, board[%d][%d]: %d\n", num, c, i+1, board[c][i+1]);
			cnt++;
			num = board[n / size][i + 1];
		}
		i++;
	}
//	printf("check L: %d, cnt: %d\n", condition[2][c] - 49, cnt);
	if (cnt > condition[2][n / size] - 49 || (cnt < condition[2][n / size] - 49 && n % size == size -1))
		return (0);
//	printf("left is good\n");
	return (1);
}

int	check_d(char **condition, char **board, int n, int size)
{
	int	i;
	int	cnt;
	int	num;
//	int	r;

//	r = n % size;
	num = board[size - 1][n % size];
	cnt = n / size;
	if (cnt == size -1)
	{
//		printf("down! here we go\n");
		cnt = 0;
		i = size - 1;
//		printf("before whlie: board[%d][%d] : %d, size: %d\n", i, r, board[i][r], size);
		while (board[i][n % size] - '0' != size)
		{
//			printf("i: %d, num: %d, board[%d][%d]: %d\n", i, num, i-1, r, board[i-1][r]);
			if (num < board[i-1][n % size])
			{
//				printf("num: %d, board[%d][%d]: %d\n", num, i -1, r, board[i-1][r]);
				cnt++;
				num = board[i-1][n % size];
			}
			i--;
		}
//		printf("%d, cnt: %d\n", condition[1][r] - 1, cnt);
		if ((condition[1][n % size] - 49) != cnt)
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
//	int	c;

//	c = n / size;
	num = board[n / size][size - 1];
	cnt = n % size;
	if (cnt == size -1)
	{
//		printf("here we go\n");
		cnt = 0;
		i = size - 1;
		while (board[n / size][i] != size && i >= 0)
		{
//			printf("i: %d\n", i);
			if (num < board[n / size][i - 1])
			{
//				printf("num: %d, board[%d][%d]: %d\n", num, c, i -1, board[c][i-1]);
				cnt++;
				num = board[n / size][i - 1];
			}
			i--;
		}
//		printf("%d, cnt: %d\n", condition[3][c] - 1, cnt);
		if ((condition[3][n / size] - 49) != cnt)
			return (0);
	}
//	printf("right is good\n");
	return (1);
}
