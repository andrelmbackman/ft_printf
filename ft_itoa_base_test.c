#include <stdio.h>
#include <stdarg.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>

static char	*zerostr()
{
	char	*str;

	str = (char *)malloc(2 * sizeof(char));
	if (!str)
		return (NULL);
	str[0] = '0';
	str[1] = '\0';
	return (str);
}

static int	itoa_base_len(long n, long base)
{
	int	length;

	length = 1;
	if (n < 0)
	{
		n *= -1;
		length++;
		if (base == 16)
			return (8);
		if (base == 8)
			return (11);
	}
	n /= base;
	while (n)
	{
		n /= base;
		length++;
	}
	printf("\nbase: %11li\nlength: %8i\nnum %% base: %4li\n", base, length, (n % base));
	return (length);
}

static void	str_reverse(char *str)
{
	char	tmp;
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (str[j])
		j++;
	j--;
	while (i < j)
	{
		tmp = str[j];
		str[j] = str[i];
		str[i] = tmp;
		i++;
		j--;
	}
}

char	*ft_itoa_base(int num, int base)
{
	char	*str;
	int		pos;
	int		len;
	int		i;
	long	n;
	long	res;

	pos = 1;
	i = 0;
	n = num;
	res = 0;
	if (num == 0)
		return (zerostr());
	if (num == 2147483647)
		n = 2147483647;
	else if (num == -2147483648)
		n = -2147483648;
	else
		n = (long)num;
	len = itoa_base_len(n, (long)base);
	if (num < 0)
	{
		num *= -1;
	}
	str = (char *)malloc((len + 1) * sizeof(char));
	while (num != 0)
	{
		res = num % base;
		if (res > 9)
			str[i] = res - 10 + 'a';
		else
			str[i] = res + '0';
		num = num / base;
		i++;
	}
	if (n < 0)
		str[i++] = '-';
	str[i] = '\0';
	str_reverse(str);
	return (str);
}

int main(void)
{
	char	*str;
	int		i;
	printf("int min: %x\n", INT_MIN - 1);
	i = 100;
	printf("\n\thex\tHEX\toct\tOCT\n");
	while (i <= 1000)
	{
		printf("\n%i\n\t%x\t%X\t%o\t%O\n", i, i, i, i, i);
		printf("HASH\t%#x\t%#X\t%#o\t%#O\n", i, i, i, i);
		i += 100;
	}
	str = ft_itoa_base(100, 2);
	printf("itoa_base binary 100: %s\n", str);
	free(str);
	str = ft_itoa_base(-100, 2);
	printf("itoa_base binary -100: %s\n", str);
	free(str);
	str = ft_itoa_base(100, 8);
	printf("itoa_base octal 100: %s\n", str);
	free(str);
	str = ft_itoa_base(-100, 8);
	printf("itoa_base octal -100: %s\n", str);
	free(str);
	str = ft_itoa_base(100, 16);
	printf("itoa_base hex 100: %s\n", str);
	free(str);
	str = ft_itoa_base(-100, 16);
	printf("itoa_base hex -100: %s\n", str);
	free(str);
	return(0);
}