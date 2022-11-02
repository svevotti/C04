/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smazzari <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/27 09:57:15 by smazzari          #+#    #+#             */
/*   Updated: 2022/11/01 12:03:21 by smazzari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

int	ft_count_digits(int nb)
{
	int	count;

	count = 0;
	if (nb == 0)
		count = 1;
	if (nb < 0)
		nb = nb * (-1);
	while (nb > 0)
	{
		nb = nb / 10;
		count++;
	}
	return (count);
}

int ft_get_multiplier(int count)
{
	int c;

	c = 1;
	while (count > 1)
	{
		c = c * 10;
		count--;
	}
	return (c);
}

void 	ft_putnbr(int nb)
{
	int	count;
	int	m;
	int	digit;

	if (nb == 0)
		ft_putchar('0');
	else
	{
		count = ft_count_digits(nb);
		m = ft_get_multiplier(count);
		if (nb < 0)
		{
			nb = nb * (-1);
			ft_putchar('-');
		}
		while (nb > 0)
		{
			digit = nb / m;
			ft_putchar('0' + digit);
			nb = nb - digit * m;
			m = m / 10;
		}
	}
}

int	main(void)
{
	ft_putnbr(42345);
	ft_putchar('\n');
	ft_putnbr(0);
	ft_putchar('\n');
	ft_putnbr(-21474);
	ft_putchar('\n');
	ft_putnbr(4);
	ft_putchar('\n');
}
