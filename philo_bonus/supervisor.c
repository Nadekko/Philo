/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   supervisor.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andjenna <andjenna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/16 16:45:43 by andjenna          #+#    #+#             */
/*   Updated: 2024/11/16 17:48:31 by andjenna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

static int	ft_set_death(t_prog *prog)
{
	int	i;
	int	time;

	time = get_time_ms() - prog->start;
	i = 0;
	while (i < prog->nb_of_philo)
	{
		if (get_time_ms() - get_value(&prog->philo[i].last_meal, prog->data) > prog->time_to_die)
		{
			prog->death_flag = 1;
			sem_wait(prog->print);
			printf("%s%d %d died%s\n", PURPLE, time, prog->philo[i].id, RESET);
			sem_post(prog->print);
			return (1);
		}
		i++;
	}
	return (0);
}

void	*ft_supervisor(void *arg)
{
	t_philo *philo;

	philo = (t_philo *)arg;
	while (1)
	{
		if (ft_set_death(philo->prog) == 1)
			return (NULL);
	}
	return (NULL);
}
