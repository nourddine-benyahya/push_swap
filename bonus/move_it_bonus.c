/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_it_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbenyahy <nbenyahy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/31 09:45:12 by nbenyahy          #+#    #+#             */
/*   Updated: 2024/04/01 01:40:34 by nbenyahy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

static void	push_it(char *move, t_var *var_a, t_var *var_b)
{
	if (!ft_strncmp(move, "pa\n", ft_strlen(move)) && var_b->size != 0)
		push(var_b, var_a, NULL);
	else if (var_a->size != 0)
		push(var_a, var_b, NULL);
}

static void	rotate_it(char *move, t_var *var_a, t_var *var_b)
{
	if (!ft_strncmp(move, "ra\n", ft_strlen(move)) && var_a->size > 1)
		rotate(var_a, NULL);
	else if (!ft_strncmp(move, "rb\n", ft_strlen(move)) && var_b->size > 1)
		rotate(var_b, NULL);
	else
	{
		if (var_b->size > 1)
			rotate(var_b, NULL);
		if (var_a->size > 1)
			rotate(var_a, NULL);
	}
}

static void	rrotate_it(char *move, t_var *var_a, t_var *var_b)
{
	if (!ft_strncmp(move, "rra\n", ft_strlen(move)) && var_a->size > 1)
		rrotate(var_a, NULL);
	else if (!ft_strncmp(move, "rrb\n", ft_strlen(move)) && var_b->size > 1)
		rrotate(var_b, NULL);
	else
	{
		if (var_b->size > 1)
			rrotate(var_b, NULL);
		if (var_a->size > 1)
			rrotate(var_a, NULL);
	}
}

static void	swap_it(char *move, t_var *var_a, t_var *var_b)
{
	if (!ft_strncmp(move, "sa\n", ft_strlen(move)) && var_a->size > 1)
		swap(var_a, NULL);
	else if (!ft_strncmp(move, "sb\n", ft_strlen(move)) && var_b->size > 1)
		swap(var_b, NULL);
	else
	{
		if (var_b->size > 1)
			swap(var_b, NULL);
		if (var_a->size > 1)
			swap(var_a, NULL);
	}
}

void	move_it(char *move, t_var *var_a, t_var *var_b)
{
	if (!ft_strncmp(move, "pa\n", ft_strlen(move)) 
		|| !ft_strncmp(move, "pb\n", ft_strlen(move)))
		push_it(move, var_a, var_b);
	else if (!ft_strncmp(move, "ra\n", ft_strlen(move)) 
		|| !ft_strncmp(move, "rb\n", ft_strlen(move))
		|| !ft_strncmp(move, "rr\n", ft_strlen(move)))
		rotate_it(move, var_a, var_b);
	else if (!ft_strncmp(move, "rra\n", ft_strlen(move)) 
		|| !ft_strncmp(move, "rrb\n", ft_strlen(move))
		|| !ft_strncmp(move, "rrr\n", ft_strlen(move)))
		rrotate_it(move, var_a, var_b);
	else
		swap_it(move, var_a, var_b);
}
