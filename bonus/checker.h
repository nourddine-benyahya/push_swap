/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbenyahy <nbenyahy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/31 09:01:26 by nbenyahy          #+#    #+#             */
/*   Updated: 2024/03/31 09:43:19 by nbenyahy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
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