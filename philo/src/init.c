#include "../include/philo.h"

void init_values(t_philo *philo, char **argv)
{
    philo->philo_num = ft_atoi(argv[1]);
    philo->time_to_die = ft_atoi(argv[2]);
    philo->time_to_eat = ft_atoi(argv[3]);
    philo->time_to_sleep = ft_atoi(argv[4]);
    if (argv[5])
        philo->times_to_eat = ft_atoi(argv[5]);
    else
        philo->times_to_eat = -1;
}

void init_philos(t_philo *philo, pthread_mutex_t *forks, char **argv)
{
    int i;

    i = 0;
    while (i < ft_atoi(argv[1]))
    {
        philo[i].id = i + 1;
        philo[i].eating = 0;
        philo[i].meals_eaten = 0;
        init_values(&philo[i], argv);
        i++;
    }
}