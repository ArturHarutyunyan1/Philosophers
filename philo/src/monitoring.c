/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitoring.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arturhar <arturhar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/15 23:12:38 by arturhar          #+#    #+#             */
/*   Updated: 2024/05/20 00:07:48 by arturhar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

int	philo_dead(t_philo *philo, size_t time)
{
	pthread_mutex_lock(philo->meal_lock);
	if (get_current_time() - philo->last_meal >= time
		&& philo->eating == 0)
		return (pthread_mutex_unlock(philo->meal_lock), 1);
	pthread_mutex_unlock(philo->meal_lock);
	return (0);
}

int	dead_check(t_philo *philo)
{
	int	i;

	i = 0;
	while (i < philo[0].philo_num)
	{
		if (philo_dead(&philo[i], philo[i].time_to_die))
		{
			action("has died", &philo[i]);
			pthread_mutex_lock(philo[0].dead_lock);
			*philo->is_dead = 1;
			pthread_mutex_unlock(philo[0].dead_lock);
			return (1);
		}
		i++;
	}
	return (0);
}

int	meals_finished(t_philo *philo)
{
	int	i;
	int	finished_eating;

	i = 0;
	finished_eating = 0;
	if (philo[0].times_to_eat == -1)
		return (0);
	while (i < philo[0].philo_num)
	{
		pthread_mutex_lock(philo[i].meal_lock);
		if (philo[i].meals_eaten >= philo[i].times_to_eat)
			finished_eating++;
		pthread_mutex_unlock(philo[i].meal_lock);
		i++;
	}
	if (finished_eating == philo[0].philo_num)
	{
		ft_usleep(philo[0].time_to_eat);
		pthread_mutex_lock(philo[0].dead_lock);
		*philo->is_dead = 1;
		pthread_mutex_unlock(philo[0].dead_lock);
		return (1);
	}
	return (0);
}

void	*monitoring(void *ptr)
{
	t_philo	*philos;

	philos = (t_philo *)ptr;
	while (1)
		if (dead_check(philos) == 1 || meals_finished(philos) == 1)
			break ;
	return (ptr);
}
