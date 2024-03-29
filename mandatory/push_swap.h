/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbenyahy <nbenyahy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/25 03:05:43 by nbenyahy          #+#    #+#             */
/*   Updated: 2024/03/28 16:36:11 by nbenyahy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "unistd.h"
#include "stdlib.h"
#include "stdbool.h"
#include "stdio.h"
#include "string.h"
#include "limits.h"

typedef struct s_stack {
	int				nbr;
	struct s_stack	*next;
}	t_stack;

typedef struct s_var {
	int		size;
	t_stack	*head;
}	t_var;

// Operations
void	push(t_var *a, t_var *b, char *mv);
void	swap(t_var *a, char *mv);
void	rrotate(t_var *a, char *mv);
void	rotate(t_var *a, char *mv);

//helpers fun
void	free_list(t_var *a);
bool	is_sorted(t_var *a);
int		find_min(t_var *a);
float	avg(t_var *a);

//sorts
void	small_stack(t_var *a, t_var *b);
void	large_stack(t_var *a, t_var *b);