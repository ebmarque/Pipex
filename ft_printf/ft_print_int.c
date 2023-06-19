/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_int.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebmarque < ebmarque@student.42porto.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/26 15:22:15 by ebmarque          #+#    #+#             */
/*   Updated: 2023/04/27 13:52:45 by ebmarque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_int(t_print *tab)
{
	int		nb;
	char	*number;
	int		len;

	nb = va_arg(tab->args, int);
	number = ft_itoa(nb);
	ft_putstr_fd(number, 1);
	len = ft_strlen(number);
	free(number);
	return (len);
}
