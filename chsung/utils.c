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

#include "universal.h"

void	print_str(const char *str)
{
	int	i;

	i = -1;
	while (str[++i] != '\0')
	{
		write(1, &str[i], 1);
	}
}

void	print_board(const char **board)
{
	int	i;
	int	j;

	i = -1;
	j = -1;
	while (++i < MAX_SIZE)
	{
		while (++j < MAX_SIZE)
		{
			write(1, &(board[i][j]), 1);
			if (j < MAX_SIZE - 1)
				write(1, " ", 1);
		}
		write(1, "\n", 1);
	}
}

int	is_invalid_arg(const char *arg)
{
	int	i;
	int	count;

	i = -1;
	count = 0;
	while (arg[++i] != '\0')
	{
		if (i >= 8 * MAX_SIZE)
			return (1);
		if (i % 2 == 0)
		{
			if ('1' <= arg[i] && arg[i] <= '0' + MAX_SIZE)
				count++;
			else
				return (1);
		}
		else
		{
			if (arg[i] != ' ')
				return (1);
		}
	}
	if (count != (MAX_SIZE * 4))
		return (1);
	return (0);
}

char	*get_constrains(const char *arg)
{
	int		i;
	int		j;
	char	*arr;

	i = -1;
	j = 0;
	arr = malloc(MAX_SIZE * 4);
	if (!arr)
		return (NULL);
	while (arg[++i] != '\0')
		if ('1' <= arg[i] && arg[i] <= '0' + MAX_SIZE)
			arr[j++] = arg[i];
	return (arr);
}
