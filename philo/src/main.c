#include "../include/philo.h"

int main(int argc, char **argv)
{
    t_philo philos[LIMIT];
    t_prog program;
    pthread_mutex_t forks[LIMIT];

    if (!validation(argc, argv))
    {
        printf("Error\n");
        return (1);
    }
    init_program(&program, philos);
    init_forks(forks, ft_atoi(argv[1]));
    init_philos(philos, &program, forks, argv);
    simulation(&program, forks);
    destroy(NULL, &program, forks); 
    return (0);
}