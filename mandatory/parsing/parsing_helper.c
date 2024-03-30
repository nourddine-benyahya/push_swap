/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_helper.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbenyahy <nbenyahy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/30 08:49:06 by nbenyahy          #+#    #+#             */
/*   Updated: 2024/03/30 09:25:18 by nbenyahy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "../push_swap.h"

void	exit_error(t_var *var_a, char **arr)
{
	if (arr)
		free2darr(arr);
	free_list(var_a);
	write(1, "Error\n", 6);
	exit(1);
}

void	hande_double(t_var *a)
{
	t_stack	*tmp_i;
	t_stack	*tmp_j;

	tmp_i = a->head;
	while (tmp_i)
	{
		tmp_j = tmp_i->next;
		while (tmp_j)
		{
			if (tmp_j->nbr == tmp_i->nbr)
				exit_error(a, NULL);
			tmp_j = tmp_j->next;
		}
		tmp_i = tmp_i->next;
	}
}

void	*free2darr(char **arr)
{
	size_t	i;

	i = 0;
	while (arr[i] != NULL)
	{
		free(arr[i]);
		i++;
	}
	free(arr);
	return (NULL);
}
