/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbenyahy <nbenyahy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/26 22:43:11 by nbenyahy          #+#    #+#             */
/*   Updated: 2024/03/28 00:27:58 by nbenyahy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push(t_var *a, t_var *b, char *mv)
{
	t_stack	*node;

	if (a->head == NULL)
		return ;
	node = a->head;
	a->head = a->head->next;
	node->next = b->head;
	b->head = node; 
	a->size--;
	b->size++;
	if (mv)
		write(1, mv, 3);
}

void	rotate(t_var *a, char *mv)
{
	t_stack	*tmp;

	tmp = a->head;
	while (tmp->next)
		tmp = tmp->next;
	tmp->next = a->head;
	a->head = a->head->next;
	tmp->next->next = NULL;
	if (mv)
		write(1, mv, 3);
}

void	swap(t_var *a, char *mv)
{
	t_stack	*tmp;

	tmp = a->head->next;
	a->head->next = a->head->next->next;
	tmp->next = a->head;
	a->head = tmp;
	if (mv)
		write(1, mv, 3);
}

void	rrotate(t_var *a, char *mv)
{
	t_stack	*tmp;
	t_stack	*prev;

	tmp = a->head;
	prev = NULL;
	while (tmp->next)
	{
		prev = tmp;
		tmp = tmp->next;
	}
	prev->next = NULL;
	tmp->next = a->head;
	a->head = tmp;
	if (mv)
		write(1, mv, 4);
}

