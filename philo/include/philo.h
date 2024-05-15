#ifndef PHILO_H
#define PHILO_H

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <unistd.h>
#include <pthread.h>
#include <limits.h>
#include <sys/time.h>

#define LIMIT 200

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
bool check_num(char **argv);
int ft_strlen(char *str);
long long	ft_atoi(const char *str);
void init_philos(t_philo *philo, t_prog *program, pthread_mutex_t *forks, char **argv);
void init_program(t_prog *program, t_philo *philo);
void init_values(t_philo *philo, char **argv);
void init_forks(pthread_mutex_t *forks, int num);
size_t	get_current_time(void);
void action(char *msg, t_philo *philo);
int philo_loop(t_philo *philo);
int	ft_usleep(size_t milliseconds);
void think(t_philo *philo);
void dream(t_philo *philo);
void eat(t_philo *philo);
void *monitoring(void *ptr);
void destroy(char *msg, t_prog *program, pthread_mutex_t *forks);
int simulation(t_prog *program, pthread_mutex_t *forks);

#endif