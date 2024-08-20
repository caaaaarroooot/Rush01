/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chsung <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/20 14:17:01 by chsung            #+#    #+#             */
/*   Updated: 2024/08/20 16:45:14 by jilee2           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

void	print_str(const char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		write(1, &str[i], 1);
		i++;
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
/*update*/
char    **makeCondition(const int n, const char *arg)
{
	char	**condition;
	int		i;

	condition = (char **)malloc(sizeof(char *) * n);
	if (!condition)
		return (0);
	i = 0;
	while (i < n)
	{
		condition[i] = (char *)malloc(sizeof(char) * n);
		if (!condition[i])
		{
			while (--i >= 0)
				free (condition[i]);
			free (condition);
			return (0);
		}
		i++;
	}
	condition = completeCondition(n, condition, arg);
	return (condition);
}

char	**completeCondition(const int n, char **condition, const char *arg)
{
	int	i;
	int	j;
	int	cnt;

	i = 0;
	j = 0;
	cnt = 0;
	while (arg[i])
	{
		if (arg[i] != ' ')
			condition[cnt][j] = arg[i];
		else
		{
			if (j == n - 1)
			{
				j = 0;
				cnt++;
			}
			else
				j++;
		}
		i++;
	}
	printf("%s %s %s %s", condition[0], condition[1], condition[2], condition[3]);
	return (condition);
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
				return (1);
		}
		i++;
	}
	if (count != (n * 4))
		return (1);
	return (0);
}
