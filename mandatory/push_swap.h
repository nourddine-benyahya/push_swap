/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbenyahy <nbenyahy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/25 03:05:43 by nbenyahy          #+#    #+#             */
/*   Updated: 2024/03/30 09:27:02 by nbenyahy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "unistd.h"
#include "stdlib.h"
#include "stdbool.h"
#include "stdio.h"
#include "string.h"
#include "limits.h"

typedef struct s_v{
	int		index[2];
	int		best_index[2];
	int		cost_moves[2];
	int		res[2];
	int		tmp_index[2];
}	t_v;

typedef struct s_stack {
	int				nbr;
	struct s_stack	*next;
}	t_stack;

typedef struct s_var {
	int		size;
	t_stack	*head;
}	t_var;

//parsing
char    **parsing(char **argv, t_var *var_a);
void	hande_double(t_var *a);
void	exit_error(t_var *var_a, char **arr);
void	*free2darr(char **arr);

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
////large stack sorts helper
int		calculate_moves(int index[2], t_var *a, t_var *b);
void	move_everything_to_b(t_var *a, t_var *b);
void	optimizing_top_moves(int index[2], t_var *a, t_var *b);
void	optimizing_bottom_moves(int index[2], t_var *a, t_var *b);