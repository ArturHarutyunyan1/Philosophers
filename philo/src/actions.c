/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arturhar <arturhar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/15 23:12:31 by arturhar          #+#    #+#             */
/*   Updated: 2024/05/23 18:37:12 by arturhar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

void	action(char *msg, t_philo *philo)
{
	size_t	time;

	pthread_mutex_lock(philo->write_lock);
	time = get_current_time() - philo->start_time;
	if (!philo_loop(philo))
		printf("%zu %d %s\n", time, philo->id, msg);
	pthread_mutex_unlock(philo->write_lock);
}

void	think(t_philo *philo)
{
	action("is thinking", philo);
}

void	dream(t_philo *philo)
{
	action("is sleeping", philo);
	ft_usleep(philo->time_to_sleep);
}

void	eat(t_philo *philo)
{
	pthread_mutex_lock(philo->l_fork);
	action("Has taken a fork", philo);
	if (philo->philo_num == 1)
	{
		ft_usleep(philo->time_to_die);
		pthread_mutex_unlock(philo->r_fork);
		return ;
	}
	pthread_mutex_lock(philo->r_fork);
	action("Has taken a fork", philo);
	philo->last_meal = get_current_time();
	action("Is eating", philo);
	ft_usleep(philo->time_to_eat);
	philo->meals_eaten++;
	pthread_mutex_unlock(philo->r_fork);
	pthread_mutex_unlock(philo->l_fork);
}
