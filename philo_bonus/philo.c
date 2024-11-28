/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andjenna <andjenna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 15:23:56 by andjenna          #+#    #+#             */
/*   Updated: 2024/11/28 18:43:31 by andjenna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

int	ft_sleep(t_philo *philo)
{
	sem_wait(philo->prog->print);
	printf("%d %d %s\n", get_time_ms() - philo->prog->start, philo->id, "is sleeping");
	sem_post(philo->prog->print);
	ft_usleep(philo->prog->time_to_sleep, philo);
	sem_wait(philo->prog->print);
	printf("%d %d %s\n", get_time_ms() - philo->prog->start, philo->id, "is thinking");
	sem_post(philo->prog->print);
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
	sem_wait(philo->prog->forks);
	sem_wait(philo->prog->print);
	printf("%d %d %s\n", get_time_ms() - philo->prog->start, philo->id, "has taken a fork");
	sem_post(philo->prog->print);
	sem_wait(philo->prog->forks);
	sem_wait(philo->prog->print);
	printf("%d %d %s\n", get_time_ms() - philo->prog->start, philo->id, "has taken a fork");
	sem_post(philo->prog->print);
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

// int ft_check_death(t_philo *philo)
// {
// 	if (get_value(&philo->prog->death_flag, philo->prog->death) == 1)
// 		return (1);
// 	// if (get_value(&philo->prog->death_flag, philo->prog->death))
// 	return (0);
// }
int	ft_check_death(t_philo *philo)
{
	if (get_time_ms() - philo->last_meal >= philo->prog->time_to_die)
	{
		// printf("%s%d %d %s%s\n", PURPLE, get_time_ms() - philo->prog->start,
		// 		philo->id, "died", RESET);
		// sem_close(philo->prog->print);
		// ft_clean_sem(philo->prog);
		sem_close(philo->prog->print);
		ft_clean_sem(philo->prog);
		exit(0);
	}
	return (0);
}

void	ft_routine(t_philo *philo)
{
	while (!ft_check_death(philo))
	{
		// if (ft_check_death(philo) == 1)
			// break ; 
		if (philo->id % 2 == 0)
			usleep(1500);
		ft_eat(philo);
		ft_sleep(philo);
		// usleep(2000);
		// ft_think(philo);
	}
	// ft_clean_sem(philo->prog);
	// exit(0);
	// terminate_process(philo->prog);
}
