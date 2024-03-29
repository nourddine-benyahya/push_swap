/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   large_stack.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbenyahy <nbenyahy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/28 02:02:37 by nbenyahy          #+#    #+#             */
/*   Updated: 2024/03/29 06:23:13 by nbenyahy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	move_everything_to_b(t_var *a, t_var *b)
{
	float	navg;

	while (a->size != 5)
	{
		navg = avg(a);
		if (a->head->nbr >= navg)
			rotate(a, "ra\n");
		else
			push(a, b, "pb\n");
	}
	small_stack(a, b);
}

void	optimizing_top_moves(int index[2], t_var *a, t_var *b)
{
	while (index[1] > 0 && index[0] > 0)
	{
		rotate(a, NULL);
		rotate(b, NULL);
		write(1, "rr\n", 3);
		index[1]--;
		index[0]--;
	}
	while (index[0]-- > 0)
		rotate(a, "ra\n");
	while (index[1]-- > 0)
		rotate(b, "rb\n");
}

void	optimizing_bottom_moves(int index[2], t_var *a, t_var *b)
{
	while (index[0] < a->size  && index[1] < b->size)
	{
		rrotate(a, NULL);
		rrotate(b, NULL);
		write(1, "rrr\n", 4);
		index[0]++;
		index[1]++;
	}
	while (index[0]++ < a->size)
		rrotate(a, "rra\n");
	while (index[1]++ < b->size)
		rrotate(b, "rrb\n");
}

void	move_it_to_top(int index[2], t_var *a, t_var *b)
{
	if (index[0] <= a->size / 2 && index[1] <= b->size / 2
		&& index[1] != 0 && index[0] != 0)
		optimizing_top_moves(index, a, b);
	else if (index[0] > a->size / 2 && index[1] > b->size / 2
		&& index[1] != 0 && index[0] != 0)
		optimizing_bottom_moves(index, a, b);
	else 
	{
		if (index[0] > a->size / 2)
			while (index[0]++ < a->size)
				rrotate(a, "rra\n");
		else
			while (index[0]-- > 0)
				rotate(a, "ra\n");
		if (index[1] > b->size / 2)
			while (index[1]++ < b->size)
				rrotate(b, "rrb\n");
		else
			while (index[1]-- > 0)
				rotate(b, "rb\n");
	}
	push(b, a, "pa\n");
}

// void	find_my_besty()
// {
	
// }

void	find_best_friend(t_var *a, t_var *b)
{
	t_stack	*tmp_a;
	t_stack	*tmp_b;
	int		index[2];
	int		mv_index[2];
	int		cost_moves;
	int		res[2];
	int		tmp_index[2];
	int		tmp_cost_moves;

	tmp_index[1] = 0;
	index[0] = 0;
	index[1] = 0;
	res[0] = 0;
	res[1] = 0;
	cost_moves = INT_MAX;
	tmp_b = b->head;
	while (tmp_b)
	{
		tmp_index[0] = 0;
		tmp_a = a->head;
		res[1] = INT_MAX;
		while (tmp_a)
		{
			res[0] = tmp_a->nbr - tmp_b->nbr;
			if (res[0] > 0 && res[0] < res[1])
			{
				res[1] = res[0];
				index[0] = tmp_index[0];
				index[1] = tmp_index[1];
			}
			tmp_a = tmp_a->next;
			tmp_index[0]++;
		}
		tmp_cost_moves = calculate_moves(index, a, b);
		if (tmp_cost_moves < cost_moves)
		{
			cost_moves = tmp_cost_moves;
			mv_index[1] = index[1];
			mv_index[0] = index[0];
		}
		tmp_b = tmp_b->next;
		tmp_index[1]++;
	}
	move_it_to_top(mv_index, a, b);
}

void	large_stack(t_var *a, t_var *b)
{
	int	min;

	move_everything_to_b(a, b);
	while (b->head != 0)
		find_best_friend(a, b);
	min = find_min(a);
	while (!is_sorted(a))
	{
		if (min < a->size / 2)
			rotate(a, "ra\n");
		else
			rrotate(a, "rra\n");
	}
}
