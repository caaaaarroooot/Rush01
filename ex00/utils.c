/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chsung <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/20 14:17:01 by chsung            #+#    #+#             */
/*   Updated: 2024/08/20 14:17:02 by chsung           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	print_str(const char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		write(1, &str[i], 1);
	}
}

void	print_borad(const int n, const char **board)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < n)
	{
		while (j < n)
		{
			write(1, &(board[i][j]), 1);
			if (j < n - 1)
				write(1, " ", 1);
		}
	}
}

int	invalid_arg(const int n, const char *arg)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (arg[i] != '\0')
	{
		if (i % 2 == 0)
		{
			if ('1' <= arg[i] && arg[i] <= '0' + n)
				count++;
			else
				return (1);
		}
		else
		{
			if (arg[i] != ' ')
				reuturn (1);
		}
	}
	if (count != (n * 4))
		return (1);
	return (0);
}
