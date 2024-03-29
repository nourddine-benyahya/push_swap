/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbenyahy <nbenyahy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/25 03:05:46 by nbenyahy          #+#    #+#             */
/*   Updated: 2024/03/29 01:10:44 by nbenyahy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	init_stack(t_var *var_a, char **str)
{
	int		i;
	t_stack	*tmp;

	i = 0;
	var_a->head = malloc(sizeof(t_stack));
	if (!var_a->head)
		return (1);
	tmp = var_a->head;
	while (str[i])
	{
		tmp -> nbr = atoi(str[i]);
		if (str[i + 1] != NULL)
		{
			tmp->next = malloc(sizeof(t_stack));
			if (!tmp->next)
				return (1);
			tmp = tmp->next;
		}
		i++;
	}
	var_a->size = i;
	tmp->next = NULL;
	return (0);
}






int	main(int argc, char *argv[])
{
	t_var	*var_a;
	t_var	*var_b;

	var_a = malloc(sizeof(t_var));
	var_b = malloc(sizeof(t_var));
	var_b->head = NULL;
	var_b->head = NULL;
	var_b->size = 0;
	init_stack(var_a, argv + 1);

	if (var_a->size <= 5)
		small_stack(var_a, var_b);
	else
		large_stack(var_a, var_b);





	// //print stack a to check if sorted
	// printf("stack a :\n");
	// t_stack	*tmp;
	// tmp = var_a->head;
	// while (tmp)
	// {
	// 	printf("<%d>\n", tmp->nbr);
	// 	tmp = tmp->next;
	// }

	// //print stack b
	// printf("stack b\n");
	// tmp = var_b->head;
	// while (tmp)
	// {
	// 	printf("<%d>\n",tmp->nbr);
	// 	tmp = tmp->next;
	// }

	free_list(var_a);
	free_list(var_b);
}