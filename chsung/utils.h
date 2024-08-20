/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chsung <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/20 14:37:52 by chsung            #+#    #+#             */
/*   Updated: 2024/08/20 14:37:55 by chsung           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H
# define MAX_SIZE 4
# include <unistd.h>
# include <stdlib.h>

void	print_str(const char *str);
void	print_borad(const char **board);
int		is_invalid_arg(const char *arg);
int		*get_constrains(const char *arg);
#endif
