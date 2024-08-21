/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   universal.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chsung <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/20 17:52:46 by chsung            #+#    #+#             */
/*   Updated: 2024/08/20 17:52:47 by chsung           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UNIVERSAL_H
# define UNIVERSAL_H
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# define MAX_SIZE 4

typedef struct s_node
{
	const char	*constrains;
	int			depth;
	char		board[MAX_SIZE][MAX_SIZE];
}	t_node;

typedef struct s_coordinate
{
	int	i;
	int	j;
}	t_coordinate;

typedef t_coordinate	t_step;

// check.c
int				is_invalid_placement(t_node *n, t_coordinate c);

// count.c
int				is_not_goal(const t_node *n);

// node.c
void			new_node(t_node *current, const t_node *prev);
void			init_node(t_node *n);

// solve.c
t_node			*solve(const char *constrains);

// utils.c
void			print_str(const char *str);
void			print_board(const t_node *n);
int				is_invalid_arg(const char *arg);
char			*get_constrains(const char *arg);
t_coordinate	get_coordinate(const int idx);

// utils2.c
int				is_duplicate_row(const t_node *n);
int				is_duplicate_col(const t_node *n);

#endif
