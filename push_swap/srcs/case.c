#include "push_swap.h"

/*
** This file has a parsing method to pick the correct operation to be applied
** to both stacks.
*/
void	next_next_case(t_stk **a, t_stk **b, int c, t_var *v)
{
	t_stk	*temp;

	temp = NULL;
	if (c == 7 && list_size(*b) > 1)
	{
		ft_putstr_fd("sb\n", v->fd);
		s_stk(b);
	}
	else if (c == 8 && list_size(*a) > 1)
	{
		ft_putstr_fd("sa\n", v->fd);
		s_stk(a);
	}
}

void	next_case(t_stk **a, t_stk **b, int c, t_var *v)
{
	t_stk	*temp;

	temp = NULL;
	if (c == 4)
	{
		ft_putstr_fd("pa\n", v->fd);
		push_ab(b, a, temp);
		free(temp);
	}
	else if (c == 5 && list_size(*b) > 1)
	{
		ft_putstr_fd("rb\n", v->fd);
		r_stk(b);
		free(temp);
	}
	else if (c == 6 && list_size(*b) > 1)
	{
		ft_putstr_fd("rrb\n", v->fd);
		rr_stk(b, temp);
		free(temp);
	}
	else
		next_next_case(a, b, c, v);
}

void	pick_case(t_stk **a, t_stk **b, int c, t_var *v)
{
	t_stk		*temp;

	temp = NULL;
	if (c == 1)
	{
		ft_putstr_fd("pb\n", v->fd);
		push_ab(a, b, temp);
		free(temp);
	}
	else if (c == 2)
	{
		ft_putstr_fd("ra\n", v->fd);
		r_stk(a);
		free(temp);
	}
	else if (c == 3 && list_size(*a) > 1)
	{
		ft_putstr_fd("rra\n", v->fd);
		rr_stk(a, temp);
	}
	else
		next_case(a, b, c, v);
}
