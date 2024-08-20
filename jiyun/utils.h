/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chsung <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/20 14:37:52 by chsung            #+#    #+#             */
/*   Updated: 2024/08/21 07:00:17 by jilee2           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H
# define MAX_SIZE 7

void	print_str(const char *str);
void	print_board(const int n, char **board);
char	**makeCondition(const int n, const char *arg);
char	**completeCondition(const int n, char **condition, const char *arg);
int		invalid_arg(const int n, const char *arg);
int		ft_sqrt(int nb);
#endif
