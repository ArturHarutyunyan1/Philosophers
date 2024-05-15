#include "../include/philo.h"

void display_info(t_philo *philo, char **argv)
{
    int i = 0;
    while (i < ft_atoi(argv[1]))
    {
        printf("ID - %d\n"
               "Eating - %d\n"
               "Meals eaten - %d\n"
               "Philo num - %d\n"
               "Times to eat - %d\n"
               "Time to die - %ld\n"
               "Time to eat - %ld\n"
               "Time to sleep - %ld\n"
               "\n----------------------------------\n",
               philo[i].id, 
               philo[i].eating, 
               philo[i].meals_eaten, 
               philo[i].philo_num, 
               philo[i].times_to_eat, 
               philo[i].time_to_die, 
               philo[i].time_to_eat, 
               philo[i].time_to_sleep);
        i++;
    }
}

int main(int argc, char **argv)
{
    t_philo philos[PHILO_MAX];
    t_prog program;
    pthread_mutex_t forks[PHILO_MAX];

    if (!validation(argc, argv))
    {
        printf("Error\n");
        return (1);
    }
    init_program(&program, philos);
    init_forks(forks, ft_atoi(argv[1]));
    init(philos, &program, forks, argv);
    thread_create(&program, forks);
    destroy(NULL, &program, forks); 
    return (0);
}