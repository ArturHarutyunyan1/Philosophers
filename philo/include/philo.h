#ifndef PHILO_H
#define PHILO_H

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <unistd.h>
#include <pthread.h>
#include <limits.h>

bool validation(int argc, char **argv);
int ft_strlen(char *str);
bool check_num(char **argv);

#endif