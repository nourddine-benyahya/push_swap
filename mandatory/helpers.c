/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helpers.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbenyahy <nbenyahy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/27 00:50:45 by nbenyahy          #+#    #+#             */
/*   Updated: 2024/03/27 00:50:59 by nbenyahy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

bool	is_sorted(t_var *a)
{
	t_stack	*tmp;
	int		nbr_tmp;

	tmp = a->head;
	nbr_tmp = tmp->nbr;
	while (tmp)
	{
		if (tmp->nbr < nbr_tmp)
			return (false);
		nbr_tmp = tmp->nbr;
		tmp = tmp->next;
	}
	return (true);
}