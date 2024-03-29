/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   large_stack.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbenyahy <nbenyahy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/28 02:02:37 by nbenyahy          #+#    #+#             */
/*   Updated: 2024/03/29 01:35:42 by nbenyahy         ###   ########.fr       */
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

int	calculate_moves(int index[2], t_var *a, t_var *b)
{
	int	a_moves;
	int	b_moves;

	if (index[0] < a->size / 2)
		a_moves = index[0];
	else
		a_moves = a->size - index[0];

	if (index[1] < b->size / 2)
		b_moves = index[1];
	else
		b_moves = b->size - index[1];
	// printf("b moves : %d a moves : %d\n", b_moves, a_moves);
	return (a_moves + b_moves);
}
void	move_it_to_top(int index[2], t_var *a, t_var *b)
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
	push(b, a, "pa\n");
}

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
				// printf("%d\n",res[0]);
				res[1] = res[0];
				index[0] = tmp_index[0];
				index[1] = tmp_index[1];
			}
			tmp_a = tmp_a->next;
			tmp_index[0]++;
		}
		// printf("stack b: %d bff stack a: %d\n", index[1], index[0]);
		tmp_cost_moves = calculate_moves(index, a, b);
		if (tmp_cost_moves < cost_moves)
		{
			cost_moves = tmp_cost_moves;
			mv_index[1] = index[1];
			mv_index[0] = index[0];
			// printf("cost moves is %d:\n", cost_moves);
		}
		tmp_b = tmp_b->next;
		tmp_index[1]++;
	}
	move_it_to_top(mv_index, a, b);
}

void	large_stack(t_var *a, t_var *b)
{
	move_everything_to_b(a, b);
	while (b->head != 0)
		find_best_friend(a, b);
	while (!is_sorted(a))
		rotate(a, "ra\n");
}
