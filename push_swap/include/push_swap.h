/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: halwahed <halwahed@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/22 13:34:13 by halwahed          #+#    #+#             */
/*   Updated: 2022/04/26 10:47:41 by halwahed         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>
# include <string.h>
# include <limits.h>
# include <ctype.h>
# include "libft.h"

# define PB 1
# define RA 2
# define RRA 3
# define PA 4
# define RB 5
# define RRB 6
# define SB 7
# define SA 8

typedef struct s_stk
{
	int				num;
	struct s_stk	*next;
	struct s_stk	*prev;
}	t_stk;

typedef struct s_var
{
	char			*line;
	char			**split;
	char			**av;
	int				ac;
	int				len;
	int				print;
	int				color;
	int				fd;
	t_stk			*a;
	t_stk			*b;
}	t_var;

/*Operations*/
void	rr_stk(t_stk **top, t_stk *temp);
void	push_ab(t_stk **a, t_stk **b, t_stk *temp);
void	r_stk(t_stk **top);
void	s_stk(t_stk **top);

/*PS parser */
int		check_sort(t_stk **a, int len);
void	check_dup(char **av, t_var *v);
int		check_numbers(char **av, t_var *v);
void	free_exit(t_var *v);

int		check_pivot(t_stk *a, int pvt, int flag);
void	pick_case(t_stk **a, t_stk **b, int c, t_var *v);
void	sort_short(t_stk **a, t_stk **b, int len, t_var *v);
void	sort_long(t_stk **a, t_stk **b, int len, t_var *v);
void	normalize_a(t_stk **a, t_stk **b, t_var *v, int pvt);
void	normalize_b(t_stk **a, t_stk **b, t_var *v, int pvt);

/* PS utils */
void	ft_exit(char *arg, int error);
t_var	*ft_init_var(t_var *v);
t_stk	*fill_list(t_var *v, char **split, t_stk *temp);
t_stk	*ft_lst_dup(t_stk *stk);
t_stk	*ft_lstsort(t_stk *stk);

/*List Auxiliary functions*/
int		list_size(t_stk *a);
void	add_back(t_stk **top, t_stk *new);
void	add_back_r(t_stk **top);
void	add_front(t_stk **top, t_stk *new);
void	free_stk(t_stk **stk);
t_stk	*ft_lst_bottom(t_stk *a);
int		ft_lstnbr(t_stk **stk, int index);
int		get_min(t_stk *stk);
int		get_max(t_stk *stk);
int		get_idx(t_stk *stk, int num, int flag );
int		get_pivot(t_stk *stk);

#endif
