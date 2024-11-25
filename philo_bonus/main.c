/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andjenna <andjenna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 11:09:11 by andjenna          #+#    #+#             */
/*   Updated: 2024/11/25 23:47:47 by andjenna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

void	start_simulation(t_philo *philo, t_prog *prog)
{
	int	i;

	i = 0;
	while (i < prog->nb_of_philo)
	{
		if ((philo[i].pid = fork()) == -1)
		{
			printf("Error : fork failed\n");
			while (i--)
				kill(philo[i].pid, SIGKILL);
			return ;
		}
		else if (philo[i].pid == 0)
		{
			ft_routine(&philo[i]);
			exit(0);
		}
		i++;
	}
	// if (sem_wait(prog->death))
	// 	terminate_process(prog);
	while (i--)
		waitpid(philo[i].pid, NULL, 0);
}

static int	ft_parse_args(int ac, char **av)
{
	if (ac < 5 || ac > 6)
	{
		printf("Error : wrong number of arguments\n");
		return (1);
	}
	else if (ft_parse_params(ac, av))
		return (1);
	return (0);
}

int	main(int ac, char **av)
{
	t_prog	prog;
	t_philo	*philo;

	if (ft_parse_args(ac, av) || ft_init_prog(&prog, ac, av))
		return (1);
	philo = malloc(sizeof(t_philo) * prog.nb_of_philo);
	if (!philo)
	{
		printf("Error : malloc failed\n");
		return (1);
	}
	ft_init_philo(philo, &prog);
	prog.philo = philo;
	prog.start = get_time_ms();
	philo->last_meal = prog.start;
	start_simulation(philo, &prog);
	// ft_free(&prog, philo);
	return (0);
}
