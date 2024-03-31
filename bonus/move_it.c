/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_it.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbenyahy <nbenyahy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/31 09:45:12 by nbenyahy          #+#    #+#             */
/*   Updated: 2024/03/31 09:52:27 by nbenyahy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void    move_it(char *move, t_var *var_a, t_var *var_b)
{
    if (!ft_strncmp(move, "pa\n", ft_strlen(move) || !ft_strncmp(move, "pb\n", ft_strlen(move)))
        push_it(move, var_a, var_b);
    else if (!ft_strncmp(move, "ra\n", ft_strlen(move) || !ft_strncmp(move, "rb\n", ft_strlen(move)))
        rotate_it(move, var_a, var_b);
}