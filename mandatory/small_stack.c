/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   small_stack.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbenyahy <nbenyahy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/28 00:51:11 by nbenyahy          #+#    #+#             */
/*   Updated: 2024/03/31 08:31:14 by nbenyahy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	sort_3(t_var *a)
{
	int	first;
	int	second;
	int	third;

	first = a->head->nbr;
	second = a->head->next->nbr;
	third = a->head->next->next->nbr;
	if (first > second && second < third && first < third)
		swap(a, "sa\n");
	else if (first > second && second > third && first > third)
	{
		swap(a, "sa\n");
		rrotate(a, "rra\n");
	}
	else if (first > second && second < third)
		rotate(a, "ra\n");
	else if (first < second && second > third && first < third)
	{
		swap(a, "sa\n");
		rotate(a, "ra\n");
	}
	else if (first < second && second > third)
		rrotate(a, "rra\n");
}

static void	sort_4(t_var *a, t_var *b)
{
	int		i;

	if (is_sorted(a))
		return ;
	i = find_min(a);
	if (i == a->size - 1)
		rrotate(a, "rra\n");
	else
		while (i-- > 0)
			rotate(a, "ra\n");
	if (is_sorted(a))
		return ;
	push(a, b, "pb\n");
	sort_3(a);
	push(b, a, "pa\n");
}

static void	sort_5(t_var *a, t_var *b)
{
	int		i;

	if (is_sorted(a))
		return ;
	i = find_min(a);
	if (i > a->size / 2)
		while (i++ < a->size)
			rrotate(a, "rra\n");
	else
		while (i-- > 0)
			rotate(a, "ra\n");
	if (is_sorted(a))
		return ;
	push(a, b, "pb\n");
	sort_4(a, b);
	push(b, a, "pa\n");
}

void	small_stack(t_var *a, t_var *b)
{
	if (a->size == 5)
		sort_5(a, b);
	else if (a->size == 4)
		sort_4(a, b);
	else if (a->size == 3)
		sort_3(a);
	else if (a->size == 2)
		if (!is_sorted(a))
			swap(a, "sa\n");
}
