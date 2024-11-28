/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andjenna <andjenna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/16 16:47:21 by andjenna          #+#    #+#             */
/*   Updated: 2024/11/28 17:58:12 by andjenna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

// static int	ft_strcmp(char *s1, char *s2)
// {
// 	int	i;

// 	i = 0;
// 	while (s1[i] && s2[i] && s1[i] == s2[i])
// 		i++;
// 	return (s1[i] - s2[i]);
// }

// void	ft_print_msg(t_philo *philo, char *msg)
// {
// 	int time;

// 	time = get_time_ms() - philo->prog->start;
// 	// if (ft_check_death(philo) == 1)
// 	// 	return ;
// 	sem_wait(philo->prog->print);
// 	printf("%d %d %s\n", time, philo->id, msg);
// 	sem_post(philo->prog->print);
// }
