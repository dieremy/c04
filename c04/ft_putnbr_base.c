#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

int ft_strlen(char *s)
{
	int i;

	i = 0;
	while(s[i])
		i++;
	return (i);
}

int check(char *base)
{
	int i;
	int j;

	i = 0;
	j = 0;
	if (base[0] == '\0' || base[1] == '\0')
		return (0);
	while (base[i])
	{
		if (base[i] == '+' || base[i] == '-')
			return (0);
		if (base[i] <= 32 || base[i] >= 126)
			return (0);
		j = i + 1;
		while (base[j])
		{
			if (base[i] == base[j])
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

void	ft_putnbr_base(int nbr, char *base)
{
	//int	size_base;
	//int	nbr_out[100];
	//int i;
	int len; //= ft_strlen;
	long nb;

	//i = 0;
	//size_base = 0;
	len = ft_strlen(base);
	nb = nbr;
	if (check(base) == 1)
	{
		if (nb < 0)
		{
			ft_putchar('-');
			nbr = -nbr;
		}
		if (nb < len)
			ft_putchar(base[nb]);
		if (nb >= len)
		{
			ft_putnbr_base(nb / len, base);
			ft_putnbr_base(nb % len, base);
		}	
	}
}

int main(int argc, char const *argv[])
{
	ft_putnbr_base(53, "0123456789abcdef");
	return 0;
}