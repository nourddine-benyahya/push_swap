/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbenyahy <nbenyahy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/26 22:43:11 by nbenyahy          #+#    #+#             */
/*   Updated: 2024/03/26 22:45:09 by nbenyahy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push(t_var *a, t_var *b)
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
}

void	rotate(t_var *a)
{
	t_stack	*tmp;

	tmp = a->head;
	while (tmp->next)
		tmp = tmp->next;
	tmp->next = a->head;
	a->head = a->head->next;
	tmp->next->next = NULL;
}
