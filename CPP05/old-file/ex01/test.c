#include <stdio.h>

int ft_sqrt(int nb)
{
	int i = 0;

	// while ((i * i) == nb)
	printf("ii = %d\n", i);
	while (i * i == nb)
	{
		printf("i = %d\n", i);
		return (i);
	}
	return (i);
}

int main()
{
	printf("%d\n", ft_sqrt(4));
	printf("%d\n", ft_sqrt(9));
}
