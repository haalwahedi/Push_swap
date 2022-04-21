#include "push_swap.h"

/*
** This funcition finds & return the number associated w/ received index
*/
int	ft_lstnbr(t_stk **stk, int index)
{
	t_stk	*temp;
	int		i;

	i = 0;
	temp = *stk;
	while (temp != NULL)
	{
		if (i == index)
			return (temp->num);
		i++;
		temp = temp->next;
	}
	return (1);
}

void	ft_lstswp(t_stk *x, t_stk *y)
{
	int	temp;

	temp = x->num;
	x->num = y->num;
	y->num = temp;
}

/*
** This function will sort the list to be used as base for
** the logic and algorithm;
*/
t_stk	*ft_lstsort(t_stk *stk)
{
	t_stk	*base;
	t_stk	*temp;
	t_stk	*comp;

	base = NULL;
	base = stk;
	temp = NULL;
	comp = NULL;
	while (base->next)
	{
		comp = base;
		temp = base->next;
		while (temp)
		{
			if (comp->num > temp->num)
				comp = temp;
			temp = temp->next;
		}
		ft_lstswp(base, comp);
		base = base->next;
	}
	return (stk);
}
