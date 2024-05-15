#include "../include/philo.h"

bool validation(int argc, char **argv)
{
    if ((argc != 5 && argc != 6) || !check_num(argv))
        return (false);
    return (true);
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
