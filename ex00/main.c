/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chsung <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/20 14:12:40 by chsung            #+#    #+#             */
/*   Updated: 2024/08/20 14:12:46 by chsung           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

int	main(int argc, char *argv[])
{
	const char	**board;

	if (argc != 2)
	{
		print_str("Error\n");
		return (0);
	}
	if (invalid_arg(MAX_SIZE, argv[1]))
	{
		print_str("Error\n");
		return (0);
	}
	board = solve();
	print_borad(MAX_SIZE, board);
	return (0);
}
