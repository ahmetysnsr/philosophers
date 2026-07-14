/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      +#+#+#+#+#+ +#+#+#+#+#+ +#+#+#+#+#+   */
/*                                                    +#+#+#+#+#+ +#+#+#+#+#+ +#+#+#+#+#+   */
/*   By: asari <asari@student.42.fr>                +#+#+#+#+#+ +#+#+#+#+#+ +#+#+#+#+#+   */
/*                                                +#+#+#+#+#+ +#+#+#+#+#+ +#+#+#+#+#+   */
/*   Created: 2026/04/02 18:09:25 by asari             +#+#+#+#+#+ +#+#+#+#+#+ +#+#+#+#+#+   */
/*   Updated: 2026/04/08 21:32:47 by asari            +#+#+#+#+#+ +#+#+#+#+#+ +#+#+#+#+#+   */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"
#include <unistd.h>

void	take_forks(t_philo *philo)
{
	if (philo->data->number_of_philosophers == 1)
	{
		pthread_mutex_lock(&philo->l_fork->fork_mutex);
		print_status(philo, "has taken a fork");
		while (!is_finished(philo->data))
			usleep(100);
		pthread_mutex_unlock(&philo->l_fork->fork_mutex);
		return ;
	}
	if (philo->philo_id % 2 == 0)
	{
		pthread_mutex_lock(&philo->r_fork->fork_mutex);
		print_status(philo, "has taken a fork");
		pthread_mutex_lock(&philo->l_fork->fork_mutex);
		print_status(philo, "has taken a fork");
	}
	else
	{
		pthread_mutex_lock(&philo->l_fork->fork_mutex);
		print_status(philo, "has taken a fork");
		pthread_mutex_lock(&philo->r_fork->fork_mutex);
		print_status(philo, "has taken a fork");
	}
} 