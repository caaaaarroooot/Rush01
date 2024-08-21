/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jilee2 <devcarrot12@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/21 17:31:17 by jilee2            #+#    #+#             */
/*   Updated: 2024/08/21 18:25:49 by jilee2           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "universal.h"

int	is_check_colup(const t_node *n)
{
	    int     i;  
        int     cnt;
        int     num;
		int		j;

        i = 0;
        cnt = 0;
		j = get_coordinate(n->depth).j;
        num = n->board[0][j];
        while (n->board[i][j] != MAX_SIZE && n->board[i][j] != '0' && i < MAX_SIZE - 1)
        {
                if (num < n->board[i+1][j])
                {
                        cnt++;
                        num = n->board[i+1][j];
                }
                i++;
        }
        if (cnt > n->constrains[j] - 49 || (cnt < n->constrains[j] - 49 &&
			n->depth / MAX_SIZE == MAX_SIZE -1)) 
                return (0);
        return (1);
}

int	is_check_rowleft(const t_node *n)
{
		int     i;  
        int     cnt;
        int     num;
		int		j;

        i = get_coordinate(n->depth).i;
        cnt = 0;
		j = 0;
        num = n->board[i][0];
        while (n->board[i][j] != MAX_SIZE && n->board[i][j] != '0' && j < MAX_SIZE - 1)
        {
                if (num < n->board[i][j + 1]) 
                {
                        cnt++;
                        num = n->board[i][j + 1];
                }
                j++;
        }
        if (cnt > n->constrains[i + MAX_SIZE] - 49 ||
			(cnt < n->constrains[i + MAX_SIZE] - 49 && n->depth % MAX_SIZE == MAX_SIZE -1))
                return (0);
        return (1);
}

int	is_check_coldown(const t_node *n)
{
        int     i;
        int     cnt;
        int     num;
		int		j;

		j = get_coordinate(n->depth).j;
        num = n->board[get_coordinate(n->depth).i][j];
        cnt = n->depth / MAX_SIZE; 
        if (cnt == MAX_SIZE -1)
        {
                cnt = 0; 
                i = MAX_SIZE - 1;
                while (n->board[i][j] - '0' != MAX_SIZE)
                {
                        if (num < n->board[i-1][j])
                        {
                                cnt++;
                                num = n->board[i-1][j];
                        }
                        i--;
                }
                if ((n->constrains[j + 1 * MAX_SIZE] - 49) != cnt)
                        return (0);
        }
        return (1);
}

int	is_check_rowright(const t_node *n)
{
		int     i;
        int     cnt;
        int     num;
		int		j;

		i = get_coordinate(n->depth).i;
        num = n->board[i][MAX_SIZE - 1];
        cnt = n->depth % MAX_SIZE;
        if (cnt == MAX_SIZE -1)
        {
                cnt = 0;
                j = MAX_SIZE - 1;
                while (n->board[i][j] != MAX_SIZE && j >= 0)
                {
                        if (num < n->board[i][j - 1])
                        {
                                cnt++;
                                num = n->board[i][j - 1];
                        }
                        j--;
                }
                if ((n->constrains[i + MAX_SIZE * 3] - 49) != cnt)
                        return (0);
        }
        return (1);
}
