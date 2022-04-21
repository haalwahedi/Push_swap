
#include "push_swap.h"

/*
** This file has the rotating operations;
** 'ra' 'rb' 'rra' 'rrb'
*/

t_stk	*rr_swap(t_stk *top, t_stk *temp)
{
	while (top->next)
		top = top->next;
	temp->num = top->num;
	temp->next = NULL;
	temp->prev = NULL;
	return (temp);
}

void	rr_bottom(t_stk **top)
{
	while ((*top))
	{
		if ((*top)->next->next == NULL)
			break ;
		*top = (*top)->next;
	}
	free((*top)->next);
	(*top)->next = NULL;
}

void	rr_stk(t_stk **top, t_stk *temp)
{
	t_stk	*a;

	a = NULL;
	temp = NULL;
	if (*top)
	{
		temp = (t_stk *)malloc(sizeof(t_stk));
		if (temp == NULL)
			return ;
		temp = rr_swap(*top, temp);
		a = *top;
		rr_bottom(top);
		*top = a;
		add_front(top, temp);
	}
}

void	r_stk(t_stk **top)
{
	if (*top)
	{
		*top = (*top)->next;
		add_back_r(top);
	}
}