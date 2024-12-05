/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doley <doley@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 13:54:27 by doley             #+#    #+#             */
/*   Updated: 2024/12/05 16:59:10 by doley            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minitalk.h"

static int	check_input(int argc, char **argv)
{
	int	i;
	char	*ampoule;

	i = 0;
	ampoule  = "💡";
	if (argc != 3)
	{
		ft_printf("Error : wrong format!\n\n"
			"%s The structure should be like that :\n\n", ampoule);
		ft_printf("                         ");
		ft_printf("./client <PID> (message)\n\n");
		ft_printf("For example : ./client 1491 HelloWorld\n");
		return (0);
	}
	while (argv[1][i])
	{
		if (argv[1][i] < '0' || argv[1][i] > '9')
		{
			ft_printf("Error : not a PID!\n\n");
			ft_printf("%s A PID must contain only digits\n", ampoule);
			return (0);
		}
		i++;
	}
	return (1);
}

int	main(int argc, char **argv)
{
	if (!check_input(argc, argv))
		return (1);
}
