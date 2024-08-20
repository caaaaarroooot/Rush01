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

#include "universal.h"

char	**solve(const int *constrains)
{
	int		i;
	char	**board;

	board = malloc(sizeof(char *) * MAX_SIZE);
	i = -1;
	while (++i < MAX_SIZE)
		board[i] = malloc(sizeof(char) * MAX_SIZE);
}
