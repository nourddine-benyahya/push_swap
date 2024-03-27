/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbenyahy <nbenyahy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/25 03:05:46 by nbenyahy          #+#    #+#             */
/*   Updated: 2024/03/27 00:50:44 by nbenyahy         ###   ########.fr       */
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

float	avg(t_var *a)
{
	float	sum;
	float	res;
	t_stack *tmp;

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

void	move_everything_to_b(t_var *a, t_var *b)
{
	float	navg;

	while (a->size != 5)
	{
		navg = avg(a);
		if (a->head->nbr >= navg)
		{
			rotate(a);
			printf("ra\n");
		}
		else
		{
			push(a, b);
			printf("pb\n");
		}
	}
}



// void	sort_5_numbers(t_var *a)
// {
// 	int	arr_a[5];
// 	int	arr_b[5];
// 	temp
// }

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
	
	// pb(var_a, var_b);
	// pb(var_a, var_b);
	// pb(var_a, var_b);
	// pb(var_b, var_a);
	move_everything_to_b(var_a, var_b);
	// printf("<%d><%d>" ,var_a->head->nbr,var_b->head->nbr);
	// free_list(var_a);
	// free_list(var_b);


	// system("leaks a.out");
	// printf("%f\n",avg(var_a));
	
	// t_stack *tmp;
	// printf("stack a\n");

	// tmp = var_a->head;
	// while (tmp)
	// {
	// 	printf("<%d>\n",tmp->nbr);
	// 	tmp = tmp->next;
	// }

	// printf("stack b\n");
	// tmp = var_b->head;
	// while (tmp)
	// {
	// 	printf("<%d>\n",tmp->nbr);
	// 	tmp = tmp->next;
	// }
}