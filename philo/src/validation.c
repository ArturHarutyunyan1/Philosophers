#include "../include/philo.h"


bool validation(int argc, char **argv)
{
    if (argc != 5 && argc != 6 || !check_num(argv))
        return (false);
    return (true);
}