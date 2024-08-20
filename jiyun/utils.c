/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chsung <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/20 14:17:01 by chsung            #+#    #+#             */
/*   Updated: 2024/08/21 06:20:23 by jilee2           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

void	print_str(const char *str)
{
	int	i;

	printf("print_str\n");
	i = 0;
	while (str[i] != '\0')
	{
		write(1, &str[i], 1);
		i++;
	}
}

void	print_board(const int n, char **board)
{
	int	i;
	int	j;

	printf("printfboard\n");
	i = 0;
	j = 0;
	while (i < n)
	{
		j = 0;
		while (j < n)
		{
			write(1, &board[i][j], 1);
			//write (1, "a", 1);
			if (j < n - 1)
				write(1, " ", 1);
			j++;
		}
		write (1, "\n", 1);
		i++;
	}
}
/*update*/
char    **makeCondition(const int n, const char *arg)
{
	char	**condition;
	int		i;

	printf("makecondition\n");
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

	printf("**completeCondition\n");
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
	return (condition);
}


int	invalid_arg(const int n, const char *arg)
{
	int	i;
	int	count;

	printf("invalid_arg\n");
	i = 0;
	count = 0;
	while (arg[i] != '\0')
	{
		if (i % 2 == 0)
		{
			if ('1' <= arg[i] && arg[i] <= '0' + n)
				count++;
			else
			{
				printf("wrong word\n");
				return (1);
			}
		}
		else
		{
			if (arg[i] != ' ')
			{
				printf("not space\n");
				return (1);
			}
		}
		i++;
	}
	if (count != (n * 4))
	{
		printf("not the case\n");
		return (1);
	}
	return (0);
}
/*
int	handling_arg(const char *arg)
{
	
}
*/
int     ft_sqrt(int nb)
{
        int     s;
        int     t;
        int     cnt;

        cnt = 0;
        if (nb <= 0)
                return (0);
        t = 0;
        s = nb / 2;
        while (s != t && cnt < 46341)
        {
                t = s;
                s = (t + nb / t) / 2;
                cnt++;
        }
        if (s * s != nb)
                return (0);
        return (s);
}
