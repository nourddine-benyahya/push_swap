/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helpers.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbenyahy <nbenyahy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/27 00:50:45 by nbenyahy          #+#    #+#             */
/*   Updated: 2024/03/29 08:04:30 by nbenyahy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	free_list(t_var *a)
{
	t_stack	*tmp;

	while (a->head)
	{
		tmp = a->head;
		a->head = a->head->next;
		free(tmp);
	}
	free(a);
}

float	avg(t_var *a)
{
	float	sum;
	float	res;
	t_stack	*tmp;

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

int	find_min(t_var *a)
{
	int		tmp_nbr;
	int		i;
	int		j;
	t_stack	*tmp;

	tmp = a->head;
	tmp_nbr = tmp->nbr;
	i = 0;
	j = i;
	while (tmp)
	{
		if (tmp->nbr <= tmp_nbr)
		{
			tmp_nbr = tmp->nbr;
			j = i;
		}
		i++;
		tmp = tmp->next;
	}
	return (j);
}
