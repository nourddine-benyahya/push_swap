/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorts_helper.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbenyahy <nbenyahy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/29 08:01:25 by nbenyahy          #+#    #+#             */
/*   Updated: 2024/03/31 08:29:57 by nbenyahy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

double	avg(t_var *a)
{
	long long int	sum;
	double			res;
	t_stack			*tmp;

	sum = 0;
	res = 0;
	tmp = a->head;
	while (tmp)
	{
		sum += tmp->nbr;
		tmp = tmp->next;
	}
	res = sum / a->size;
	return (res);
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
	return (a_moves + b_moves);
}

void	move_everything_to_b(t_var *a, t_var *b)
{
	double	navg;

	while (a->size != 5)
	{
		navg = avg(a);
		if (a->head->nbr > navg)
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
	while (index[0] < a->size && index[1] < b->size)
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
