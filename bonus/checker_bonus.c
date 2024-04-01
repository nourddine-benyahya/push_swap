/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbenyahy <nbenyahy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/31 09:09:04 by nbenyahy          #+#    #+#             */
/*   Updated: 2024/04/01 01:40:40 by nbenyahy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

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

int	is_move(char *move)
{
	return (!ft_strncmp(move, "pa\n", ft_strlen(move)) 
		|| !ft_strncmp(move, "pb\n", ft_strlen(move)) 
		|| !ft_strncmp(move, "ra\n", ft_strlen(move)) 
		|| !ft_strncmp(move, "rb\n", ft_strlen(move)) 
		|| !ft_strncmp(move, "rra\n", ft_strlen(move)) 
		|| !ft_strncmp(move, "rrb\n", ft_strlen(move)) 
		|| !ft_strncmp(move, "rrr\n", ft_strlen(move)) 
		|| !ft_strncmp(move, "ss\n", ft_strlen(move))
		|| !ft_strncmp(move, "rr\n", ft_strlen(move)) 
		|| !ft_strncmp(move, "sa\n", ft_strlen(move)) 
		|| !ft_strncmp(move, "sb\n", ft_strlen(move)));
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

void	read_moves(t_var *var_a, t_var *var_b)
{
	char	*move;

	while (1)
	{
		move = get_next_line(STDIN_FILENO);
		if (move == NULL)
		{
			free(move);
			break ;
		}
		if (!is_move(move))
		{
			free_list(var_a);
			free_list(var_b);
			free(move);
			write(2, "Error\n", 6);
			exit(1);
		}
		move_it(move, var_a, var_b);
		free(move);
	}
}

int	main(int argc, char **argv)
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
	read_moves(var_a, var_b);
	if (is_sorted(var_a) && var_b->size == 0)
		write(1, "OK\n", 3);
	else
		write(1, "KO\n", 3);
	free_list(var_a);
	free_list(var_b);
}
