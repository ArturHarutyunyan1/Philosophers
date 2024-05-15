#ifndef PHILO_H
#define PHILO_H

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <unistd.h>
#include <pthread.h>
#include <limits.h>
#include <sys/time.h>


#define PHILO_MAX 300

typedef struct s_philo
{
    pthread_t thread;
    int id;
    int eating;
    int meals_eaten;
    int philo_num;
    int times_to_eat;
    int *is_dead;
    size_t time_to_die;
    size_t time_to_eat;
    size_t time_to_sleep;
    size_t start_time;
    size_t last_meal;
    pthread_mutex_t *write_lock;
    pthread_mutex_t *dead_lock;
    pthread_mutex_t *meal_lock;
    pthread_mutex_t *r_fork;
    pthread_mutex_t *l_fork;
} t_philo;

typedef struct s_prog
{
    int dead;
    pthread_mutex_t write_lock;
    pthread_mutex_t dead_lock;
    pthread_mutex_t meal_lock;
    t_philo *philos;
}t_prog;

bool validation(int argc, char **argv);
int ft_strlen(char *str);
bool check_num(char **argv);
long long	ft_atoi(const char *str);
void init(t_philo *philo, t_prog *program, pthread_mutex_t *forks, char **argv);
size_t	get_current_time(void);
void action(char *msg, t_philo *philo, int id);
void think(t_philo *philo);
void philo_sleep(t_philo *philo);
void eat(t_philo *philo);
void destroy(char *msg, t_prog *program, pthread_mutex_t *forks);
void *monitoring(void *ptr);
int	thread_create(t_prog *program, pthread_mutex_t *forks);
int	philosopher_dead(t_philo *philo, size_t time_to_die);
int	ft_usleep(size_t milliseconds);
void init_forks(pthread_mutex_t *forks, int num);
int dead(t_philo *philo);
void init_program(t_prog *program, t_philo *philo);
#endif