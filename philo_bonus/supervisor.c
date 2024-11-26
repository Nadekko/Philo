/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   supervisor.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andjenna <andjenna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/16 16:45:43 by andjenna          #+#    #+#             */
/*   Updated: 2024/11/26 16:04:46 by andjenna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

void	terminate_process(t_prog *prog)
{
	int	i;

	i = 0;
	ft_clean_sem(prog);
	while (i < prog->nb_of_philo)
	{
		kill(prog->philo[i].pid, SIGKILL);
		i++;
	}
}

// static int	ft_set_death(t_prog *prog)
// {
// 	int	i;
// 	int	time;

// 	time = get_time_ms() - prog->start;
// 	i = 0;
// 	while (i < prog->nb_of_philo)
// 	{
// 		if (get_time_ms() - prog->philo[i].last_meal >= prog->time_to_die)
// 		{
// 			sem_wait(prog->print);
// 			printf("%s%d %d %s%s\n", PURPLE, get_time_ms() - prog->start,
// 				   prog->philo[i].id, "died", RESET);
// 			return (1);
// 		}
// 		i++;
// 	}
// 	return (0);
// }

// void	*ft_supervisor(void *arg)
// {
// 	t_prog	*prog;

// 	prog = (t_prog *)arg;
// 	while (1)
// 	{
// 		if (ft_set_death(prog))
// 		{
// 			terminate_process(prog);
// 			sem_post(prog->death);
// 			break ;
// 		}
// 		usleep(1000);
// 	}
// 	return (NULL);
// }
