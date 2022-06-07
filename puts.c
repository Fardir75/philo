# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <string.h>
# include <pthread.h>
# include <sys/time.h>

void	ft_putnbr_base(unsigned int nbr, char *base)
{
	unsigned int	len;

	len = strlen(base);
	if (nbr / len == 0)
		write(1, &base[nbr % len], 1);
	else
	{
		ft_putnbr_base (nbr / len, base);
		ft_putnbr_base (nbr % len, base);
	}
}

int main()
{
	ft_putnbr_base(100, "0123456789abcdef");
	printf("\n");
}