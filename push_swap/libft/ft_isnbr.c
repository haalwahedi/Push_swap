#include "libft.h"

int	ft_isnbr(char *s)
{
	int		i;

	i = 0;
	if (s[i] == '-' || s[i] == '+')
		i++;
	while (s[i])
	{
		if (ft_isdigit(s[i]) != 1)
			return (0);
		i++;
	}
	return (1);
}
