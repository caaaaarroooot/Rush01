/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   recur.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jilee2 <devcarrot12@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/20 17:33:07 by jilee2            #+#    #+#             */
/*   Updated: 2024/08/20 18:10:04 by jilee2           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RECUR_H
#define RECUR_H

char	**recur_board(char **condition, char **board, int n, int size);
int		recur_possible(char **condition, char **board, int n, int size);
#endif
