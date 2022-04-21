#include "libft.h"

int	*ft_vcalloc(size_t count, int value)
{
	size_t		i;
	int			*mem;

	i = 0;
	mem = (int *)malloc(count * sizeof(int));
	if (!mem)
		return (NULL);
	while (i < count)
	{
		mem[i] = value;
		i++;
	}
	return (mem);
}
