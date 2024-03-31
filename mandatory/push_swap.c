/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbenyahy <nbenyahy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/25 03:05:46 by nbenyahy          #+#    #+#             */
/*   Updated: 2024/03/31 08:29:46 by nbenyahy         ###   ########.fr       */
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

int	main(int argc, char *argv[])
{
	t_var	*var_a;
	t_var	*var_b;

	if (argc == 1)
		return (1);
	var_a = malloc(sizeof(t_var));
	var_b = malloc(sizeof(t_var));
	var_b->head = NULL;
	var_b->head = NULL;
	var_b->size = 0;
	parsing(argv, var_a);
	if (is_sorted(var_a))
		return (0);
	if (var_a->size <= 5)
		small_stack(var_a, var_b);
	else
		large_stack(var_a, var_b);
	free_list(var_a);
	free_list(var_b);
}
