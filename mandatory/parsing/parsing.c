/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbenyahy <nbenyahy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/29 22:20:08 by nbenyahy          #+#    #+#             */
/*   Updated: 2024/03/30 09:53:02 by nbenyahy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

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
		if ((res > LLONG_MAX && sign == 1) || (res * sign < INT_MIN))
			exit_error(var_a, arr);
		nptr++;
	}
	if (*nptr)
		exit_error(var_a, arr);
	return (res * sign);
}

void	chack_numbers(char **argv, t_var *var_a)
{
	int		i;
	int		j;
	int		nbr_cont;
	char	**arr;
	t_stack	*tmp;

	i = 1;
	nbr_cont = 0;
	var_a->head = malloc(sizeof(t_stack));
	if (!var_a->head)
		return ;
	tmp = var_a->head;
	while (argv[i])
	{
		j = 0;
		arr = ft_split(argv[i], ' ');
		if (!arr || arr[j] == NULL)
			exit_error(var_a, arr);
		while (arr[j])
		{
			tmp->nbr = ft_super_atoi(arr[j], var_a, arr);
			tmp->next = NULL;
			nbr_cont++;
			var_a->size = nbr_cont;
			if (arr[j + 1] != NULL || argv[i + 1] != NULL)
			{
				tmp->next = malloc(sizeof(t_stack));
				if (!tmp->next)
					return ;
				tmp = tmp->next;
			}
			j++;
		}
		arr = free2darr(arr);
		i++;
	}
	hande_double(var_a);
	return ;
}

char	**parsing(char **argv, t_var *var_a)
{
	chack_numbers(argv, var_a);
	return (argv);
}
