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
# define MAX_SIZE 4

typedef struct s_node
{
	char	board[MAX_SIZE][MAX_SIZE];
}	t_node;

typedef struct s_stack
{
	struct s_node	*first;
	struct s_node	*last;
	unsigned int	len;
}	t_stack;

typedef struct s_step
{
	const int	i_step;
	const int	j_step;
}	t_step;

// count.c
int		is_violate(const t_node *n, const int i, const int j, const char *constrains);

// node.c
t_node	*new_node(void);
t_node	*cp_node(const t_node *src);
t_node	*make_first_node(const char *constrains);

// solve.c
t_node	*solve(const char *constrains);

// utils.c
void	print_str(const char *str);
void	print_board(t_node *n);
int		is_invalid_arg(const char *arg);
int		*get_constrains(const char *arg);

#endif
