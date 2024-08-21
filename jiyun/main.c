/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jilee2 <devcarrot12@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/20 14:52:05 by jilee2            #+#    #+#             */
/*   Updated: 2024/08/21 13:31:34 by jilee2           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
 	Rush01 - skyscrapers N x N
	dev: jilee2, yuskim, chsung, minjuki3
	2024. 8. 20 (Tue)
 */
#include "utils.h"
#include <stdlib.h>
#include "solve.h"
#include <stdio.h>

int	main(int argc, char **argv)
{
	char	**board;
	char	**condition;
	int		size;

	printf("strat\n");
	if (argc != 2)
	{
		print_str("argc Error\n");
		return (1);
	}
	size = handling_arg(argv[1]);
	if (size == 0 || invalid_arg(size, argv[1]) == 1)
        {
                print_str("invalid Error\n");
                return (0);
        }
//	printf("%d\n", size);
	condition = makeCondition(size, argv[1]);
        board = solve(size, condition);
//        print_borad(MAX_SIZE, board);
/*
	i = 0;
	while (condition[i] || board[i])
	{
		if (condition[i])
			free(condition[i]);
		if (board[i])
			free(board[i]);
		i++;
	}
	free(condition);
	free(board);
	*/
	board_free(board, condition);
	printf("end\n");
	return (0);
}
