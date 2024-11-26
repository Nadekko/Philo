/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andjenna <andjenna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 15:23:56 by andjenna          #+#    #+#             */
/*   Updated: 2024/11/26 16:23:37 by andjenna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

int	ft_sleep(t_philo *philo)
{
	if (ft_check_death(philo) == 1)
		return (1);
	ft_print_msg(philo, "is sleeping");
	ft_usleep(philo->prog->time_to_sleep, philo);
	ft_print_msg(philo, "is thinking");
	return (0);
}

// void	ft_think(t_philo *philo)
// {
// 	// int	time;

// 	ft_print_msg(philo, "is thinking");
// 	// if (philo->prog->time_to_eat > philo->prog->time_to_sleep)
// 	// {
// 	// 	time = philo->prog->time_to_eat - philo->prog->time_to_sleep + 1;
// 	// 	ft_usleep(time, philo);
// 	// }
// }

int	ft_eat(t_philo *philo)
{
	if (ft_check_death(philo) == 1)
		return (1);
	sem_wait(philo->prog->forks);
	ft_print_msg(philo, "has taken a fork");
	sem_wait(philo->prog->forks);
	ft_print_msg(philo, "has taken a fork");
	philo->last_meal = get_time_ms();
	sem_wait(philo->prog->print);
	printf("%s%d %d %s%s\n", YELLOW, get_time_ms() - philo->prog->start,
		philo->id, "is eating", RESET);
	sem_post(philo->prog->print);
	ft_usleep(philo->prog->time_to_eat, philo);
	sem_post(philo->prog->forks);
	sem_post(philo->prog->forks);
	philo->nb_eaten++;
	return (0);
}

int	ft_check_death(t_philo *philo)
{
	if (get_time_ms() - philo->last_meal >= philo->prog->time_to_die)
	{
		sem_wait(philo->prog->print);
		printf("%s%d %d %s%s\n", PURPLE, get_time_ms() - philo->prog->start,
				philo->id, "died", RESET);
		sem_close(philo->prog->print);
		sem_post(philo->prog->death);
		return (1);
	}
	return (0);
}

void	ft_routine(t_philo *philo)
{
	// pthread_t	supervisor;

	// pthread_create(&supervisor, NULL, ft_supervisor, philo);
	// if (!supervisor)
	// {
	// 	printf("Error : pthread_create failed\n");
	// 	return ;
	// }
	while (1)
	{
		if (ft_check_death(philo) == 1)
			break ;
		if (philo->id % 2 == 0)
			usleep(1500);
		if (ft_eat(philo))
			break ;
		if (ft_sleep(philo))
			break ;
		// ft_think(philo);
	}
	printf("la\n");
	ft_clean_sem(philo->prog);
	free(philo->prog->philo);
}
