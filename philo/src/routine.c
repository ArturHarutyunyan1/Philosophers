#include "../include/philo.h"

int dead(t_philo *philo)
{
	pthread_mutex_lock(philo->dead_lock);
	if (*philo->is_dead == 1)
		return (pthread_mutex_unlock(philo->dead_lock), 1);
	pthread_mutex_unlock(philo->dead_lock);
	return (0);
}

void *routine(void *ptr)
{
	t_philo	*philo;

	philo = (t_philo *)ptr;
	if (philo->id % 2 == 0)
		ft_usleep(1);
	while (!dead(philo))
	{
		eat(philo);
		philo_sleep(philo);
		think(philo);
	}
	return (ptr);
}

int	thread_create(t_prog *program, pthread_mutex_t *forks)
{
	pthread_t	observer;
	int			i;

	if (pthread_create(&observer, NULL, &monitoring, program->philos) != 0)
		destroy("Thread creation error", program, forks);
	i = 0;
	while (i < program->philos[0].philo_num)
	{
		if (pthread_create(&program->philos[i].thread, NULL, &routine,
				&program->philos[i]) != 0)
			destroy("Thread creation error", program, forks);
		i++;
	}
	i = 0;
	if (pthread_join(observer, NULL) != 0)
		destroy("Thread join error", program, forks);
	while (i < program->philos[0].philo_num)
	{
		if (pthread_join(program->philos[i].thread, NULL) != 0)
			destroy("Thread join error", program, forks);
		i++;
	}
	return (0);
}