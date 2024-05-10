#include "../include/philo.h"

int main(int argc, char **argv)
{
    if (!validation(argc, argv))
    {
        printf("Error\n");
        return (1);
    }
    return (0);
}