/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jilee2 <devcarrot12@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/20 14:52:05 by jilee2            #+#    #+#             */
/*   Updated: 2024/08/20 17:09:51 by jilee2           ###   ########.fr       */
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

int	main(int argc, char **argv)
{
	char	**board;
	char	**condition;
	int		i;

	if (argc != 2)
	{
		// write로 바꾸기
		print_str("argc Error\n");
		return (1);
	}
	if (invalid_arg(MAX_SIZE, argv[1]))
        {
                print_str("invalid Error\n");
                return (0);
        }
	condition = makeCondition(MAX_SIZE, argv[1]);
        board = solve(MAX_SIZE, condition);
//        print_borad(MAX_SIZE, board);
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
	return (0);
}
