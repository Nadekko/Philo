/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andjenna <andjenna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 15:33:50 by andjenna          #+#    #+#             */
/*   Updated: 2024/11/16 17:38:48 by andjenna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"


int	get_value(int *value, sem_t *data)
{
	int	ret;

	sem_wait(data);
	ret = *value;
	sem_post(data);
	return (ret);
}

void	set_value(int *value, int new_value, sem_t *data)
{
	sem_wait(data);
	value = &new_value;
	sem_post(data);
}

void	ft_usleep(int time, t_philo *philo)
{
	int	start;

	start = get_time_ms();
	while (get_time_ms() - start < time)
	{
		if (philo->prog->death_flag == 1)
			return ;
		usleep(100);
	}
}

int	get_time_ms(void)
{
	struct timeval	time;

	if (gettimeofday(&time, NULL) == -1)
		write(2, "gettimeofday() error\n", 22);
	return ((time.tv_sec * 1000) + (time.tv_usec / 1000));
}
