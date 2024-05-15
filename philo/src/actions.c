#include "../include/philo.h"

void think(t_philo *philo)
{
    action("Is thinking", philo, philo->id);
}

void philo_sleep(t_philo *philo)
{
    action("Is sleeping", philo, philo->id);
    ft_usleep(philo->time_to_sleep);
}

void eat(t_philo *philo)
{
	pthread_mutex_lock(philo->r_fork);
	action("has taken a fork", philo, philo->id);
	if (philo->philo_num == 1)
	{
		ft_usleep(philo->time_to_die);
		pthread_mutex_unlock(philo->r_fork);
		return ;
	}
	pthread_mutex_lock(philo->l_fork);
	action("has taken a fork", philo, philo->id);
	philo->eating = 1;
	action("is eating", philo, philo->id);
	pthread_mutex_lock(philo->meal_lock);
	philo->last_meal = get_current_time();
	philo->meals_eaten++;
	pthread_mutex_unlock(philo->meal_lock);
	ft_usleep(philo->time_to_eat);
	philo->eating = 0;
	pthread_mutex_unlock(philo->l_fork);
	pthread_mutex_unlock(philo->r_fork);
}
