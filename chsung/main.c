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
	const char	*constrains;

	if (argc != 2 || is_invalid_arg(argv[1]))
	{
		print_str("Error\n");
		return (0);
	}
	constrains = get_constrains(argv[1]);
	board = solve(constrains);
	print_borad(board);
	return (0);
}
