/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andjenna <andjenna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 15:23:56 by andjenna          #+#    #+#             */
/*   Updated: 2024/11/16 17:52:31 by andjenna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

void	ft_sleep(t_philo *philo)
{
	ft_print_msg(philo, "is sleeping");
	ft_usleep(philo->prog->time_to_sleep, philo);
}

void	ft_think(t_philo *philo)
{
	ft_print_msg(philo, "is thinking");
}

void	ft_eat(t_philo *philo)
{
	sem_wait(philo->prog->forks);
	sem_wait(philo->prog->forks);
	ft_print_msg(philo, "has taken a fork");
	ft_print_msg(philo, "has taken a fork");
	philo->last_meal = get_time_ms();
	ft_print_msg(philo, "is eating");
	ft_usleep(philo->prog->time_to_eat, philo);
	sem_post(philo->prog->forks);
	sem_post(philo->prog->forks);
	philo->nb_eaten++;
}

int	ft_check_death(t_philo *philo)
{
	if (philo->prog->death_flag == 1)
		return (1);
	return (0);
}

void	ft_routine(t_philo *philo)
{
	pthread_t	supervisor;

	pthread_create(&supervisor, NULL, ft_supervisor, philo);
	if (!supervisor)
	{
		printf("Error : pthread_create failed\n");
		return ;
	}
	while (1)
	{
		if (ft_check_death(philo) == 1)
			exit(0);
		if (philo->id % 2 == 0)
			usleep(1000);
		ft_eat(philo);
		ft_sleep(philo);
		ft_think(philo);
	}
}
