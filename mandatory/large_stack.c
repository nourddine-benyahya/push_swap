/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   large_stack.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbenyahy <nbenyahy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/28 02:02:37 by nbenyahy          #+#    #+#             */
/*   Updated: 2024/03/29 08:47:15 by nbenyahy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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

void	my_besty(t_var	*a, t_stack *b, t_v *vr)
{
	t_stack	*tmp_a;

	tmp_a = a->head;
	vr->tmp_index[0] = 0;
	vr->res[1] = INT_MAX;
	while (tmp_a)
	{
		vr->res[0] = tmp_a->nbr - b->nbr;
		if (vr->res[0] > 0 && vr->res[0] < vr->res[1])
		{
			vr->res[1] = vr->res[0];
			vr->index[0] = vr->tmp_index[0];
			vr->index[1] = vr->tmp_index[1];
		}
		tmp_a = tmp_a->next;
		vr->tmp_index[0]++;
	}
}

void	save_moves(t_v *vr, t_var *a, t_var *b)
{
	vr->cost_moves[0] = calculate_moves(vr->index, a, b);
	if (vr->cost_moves[0] < vr->cost_moves[1])
	{
		vr->cost_moves[1] = vr->cost_moves[0];
		vr->best_index[1] = vr->index[1];
		vr->best_index[0] = vr->index[0];
	}
}

void	find_best_friend(t_var *a, t_var *b)
{
	t_stack	*tmp_b;
	t_v		vr;

	vr.tmp_index[1] = 0;
	vr.index[0] = 0;
	vr.index[1] = 0;
	vr.res[0] = 0;
	vr.res[1] = 0;
	vr.cost_moves[1] = INT_MAX;
	tmp_b = b->head;
	while (tmp_b)
	{
		my_besty(a, tmp_b, &vr);
		save_moves(&vr, a, b);
		tmp_b = tmp_b->next;
		vr.tmp_index[1]++;
	}
	move_it_to_top(vr.best_index, a, b);
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
