#include "../include/philo.h"

int ft_strlen(char *str)
{
    int i;

    i = 0;
    while (str[i])
        i++;
    return (i);
}

long long	ft_atoi(const char *str)
{
	long long	neg;
	long long	num;
	int			i;

	i = 0;
	neg = 1;
	num = 0;
	while ((str[i] == ' ' || (str[i] == '\n') || (str[i] == '\t')
			|| (str[i] == '\v') || (str[i] == '\f') || str[i] == '\r'))
		i++;
	if ((str[i] == '-') || (str[i] == '+'))
	{
		if (str[i] == '-')
			neg *= -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		num = num * 10 + (str[i] - 48);
		i++;
	}
	if (num * neg > INT_MAX || num * neg < INT_MIN)
        return (0);
	return (num * neg);
}

bool check_num(char **argv)
{
    int i;
    int j;

    i = 1;
    while (argv[i])
    {
        j = 0;
        while (argv[i][j])
        {
            if (argv[i][j] != '-' && (argv[i][j] < '0' || argv[i][j] > '9'))
                return (false);
            if (argv[i][j] == '-')
                return (false);
            j++;
        }
        if (ft_strlen(argv[i]) > 10 || ft_atoi(argv[i]) == 0)
            return (false);
        i++;
    }
    return (true);
}