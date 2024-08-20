/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   recur.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jilee2 <devcarrot12@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/20 17:33:07 by jilee2            #+#    #+#             */
/*   Updated: 2024/08/21 00:26:04 by jilee2           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RECUR_H
#define RECUR_H

void	recur_board(char **condition, char **board, int n, int size);
int		recur_possible(char **condition, char **board, int n, int size);
int		check_row(char **board, int n, int size);
int		check_col(char **board, int n, int size);
int		check_u(char **condition, char **board, int n, int size);
int		check_d(char **condition, char **board, int n, int size);
int		check_l(char **condition, char **board, int n, int size);
int		check_r(char **condition, char **board, int n, int size);
#endif
