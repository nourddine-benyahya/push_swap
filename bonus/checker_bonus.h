/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbenyahy <nbenyahy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/31 09:01:26 by nbenyahy          #+#    #+#             */
/*   Updated: 2024/04/01 03:20:16 by nbenyahy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_BONUS_H
# define CHECKER_BONUS_H

# include "libft.h"
# include "stdbool.h"

typedef struct s_stack {
	int				nbr;
	struct s_stack	*next;
}	t_stack;

typedef struct s_var {
	int		size;
	t_stack	*head;
}	t_var;

//parsing
void	parsing(char **argv, t_var *var_a);
void	exit_error(t_var *var_a, char **arr);
void	*free2darr(char **arr);
void	free_list(t_var *a);

// Operations
void	push(t_var *a, t_var *b, char *mv);
void	swap(t_var *a, char *mv);
void	rrotate(t_var *a, char *mv);
void	rotate(t_var *a, char *mv);

// checkers move
void	move_it(char *move, t_var *var_a, t_var *var_b);

#endif