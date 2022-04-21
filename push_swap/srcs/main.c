/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: halwahed <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/24 14:28:32 by halwahed          #+#    #+#             */
/*   Updated: 2022/03/29 14:29:43 by halwahed         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* this function is rsponsible off filling stack a, after confirming that the 
* input parameter is a string of numbers */

char	**fill_args(t_var *v, int ac, char **av)
{
	v->fd = 1;
	if (ac == 2)
		v->split = ft_split(av[1], ' ');
	else
		v->split = &av[1];
	return (v->split);
}
/* this function covers up all the logic behind the whole program, and dealing 
with the errors that we might encounter */

void	push_swap(t_var *v, int ac, char **av)
{
	t_stk	*stk;

	stk = NULL;
	v->split = fill_args(v, ac, av);
	check_dup(v->split);
	check_numbers(v->split);
	v->a = fill_list(v, v->split, stk);
	if (check_sort(&v->a, list_size(v->a)) == 1)
		ft_exit("ERROR - invalid list of arguments.\n", 0);
	v->len = list_size(v->a);
	free_stk(&stk);
	if (v->len <= 10)
		sort_short(&(v->a), &(v->b), v->len, v);
	else
		sort_long(&(v->a), &(v->b), v->len, v);
	if (ac == 2 || (ac == 3 && v->fd != 1))
		ft_freearray(v->split);
	close(v->fd);
}
/* the steps of running the program */

void	ft_help(void)
{
    ft_putstr_fd ("Push_Swap: how to ... /n", 1);
    ft_putstr_fd ("To run the program write ... /n", 1);
    ft_putstr_fd ("./push_swap \"set of numbers\"\n", 1);
}
/* if there is an error exit */

void	ft_exit(char *arg, int error)
{
	if (error != 0)
		ft_putstr_fd(arg, 2);
	exit(error);
}
/* the program starts here */

int		main(int ac, char **av)
{
	t_var	*v;

	v = NULL;
	if (ac < 2)
    	ft_exit(0, 1);
	else
	{
    	v = ft_init_var(v);
    	if (!ft_strncmp(av[1], "-h", 1))
        	ft_help();
    	else
        	push_swap(v, ac, av);
    	free(v);
		v = NULL;
    }
}
