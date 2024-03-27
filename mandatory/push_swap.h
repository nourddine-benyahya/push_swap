/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbenyahy <nbenyahy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/25 03:05:43 by nbenyahy          #+#    #+#             */
/*   Updated: 2024/03/27 00:51:39 by nbenyahy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "unistd.h"
#include "stdlib.h"
#include "stdbool.h"
#include "stdio.h"
#include "string.h"

typedef struct s_stack {
	int				nbr;
	struct s_stack	*next;
}	t_stack;

typedef struct s_var {
	int		size;
	t_stack	*head;
}	t_var;

// Operations
void	push(t_var *a, t_var *b);
void	rotate(t_var *a);

//helpers fun
bool	is_sorted(t_var *a);