/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbenyahy <nbenyahy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/29 22:20:08 by nbenyahy          #+#    #+#             */
/*   Updated: 2024/04/01 01:40:49 by nbenyahy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../checker_bonus.h"

void	exit_error(t_var *var_a, char **arr)
{
	if (arr)
		free2darr(arr);
	free_list(var_a);
	write(2, "Error\n", 6);
	exit(1);
}

static void	hande_double(t_var *a)
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

static int	ft_super_atoi(const char *nptr, t_var *var_a, char **arr)
{
	unsigned long long	res;
	int					sign;

	res = 0;
	sign = 1;
	while (*nptr == ' ' || (*nptr >= 9 && *nptr <= 13))
		nptr++;
	if (*nptr == '-' || *nptr == '+')
	{
		if (*nptr == '-')
			sign = -1;
		nptr++;
	}
	if (!*nptr || !ft_isdigit(*nptr))
		exit_error(var_a, arr);
	while (*nptr && ft_isdigit(*nptr))
	{
		res = (res * 10) + (*nptr - '0');
		if ((res > INT_MAX && sign == 1) || (res > 2147483648 && sign == -1))
			exit_error(var_a, arr);
		nptr++;
	}
	if (*nptr)
		exit_error(var_a, arr);
	return (res * sign);
}

void	pars_args(char **argv, t_var **var_a, t_stack **tmp, int i)
{
	int		j;
	char	**arr;

	j = 0;
	arr = ft_split(argv[i], ' ');
	if (!arr || arr[j] == NULL)
		exit_error((*var_a), arr);
	while (arr[j])
	{
		(*tmp)->nbr = ft_super_atoi(arr[j], (*var_a), arr);
		(*tmp)->next = NULL;
		(*var_a)->size += 1;
		if (arr[j + 1] != NULL || argv[i + 1] != NULL)
		{
			(*tmp)->next = malloc(sizeof(t_stack));
			if (!(*tmp)->next)
				return ;
			(*tmp) = (*tmp)->next;
			(*tmp)->next = NULL;
		}
		j++;
	}
	arr = free2darr(arr);
}

void	parsing(char **argv, t_var *var_a)
{
	int		i;
	t_stack	*tmp;

	i = 1;
	var_a->size = 0;
	var_a->head = malloc(sizeof(t_stack));
	if (!var_a->head)
		return ;
	tmp = var_a->head;
	while (argv[i])
	{
		pars_args(argv, &var_a, &tmp, i);
		i++;
	}
	hande_double(var_a);
}
