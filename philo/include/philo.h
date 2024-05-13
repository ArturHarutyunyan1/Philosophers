#ifndef PHILO_H
#define PHILO_H

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <unistd.h>
#include <pthread.h>
#include <limits.h>

#define PHILO_MAX 300

typedef struct s_philo
{
    pthread_t thread;
    int id;
    int eating;
    int meals_eaten;
    int philo_num;
    int times_to_eat;
    size_t time_to_die;
    size_t time_to_eat;
    size_t time_to_sleep;
} t_philo;

bool validation(int argc, char **argv);
int ft_strlen(char *str);
bool check_num(char **argv);
long long	ft_atoi(const char *str);
void init_philos(t_philo *philo, pthread_mutex_t *forks, char **argv);

#endif