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

int	ft_count_digits(int n)
{
	int	c;

	c = 1;
	if (n == 0)
	{
		c = 1;
	}
	if (n < 0)
	{
		n = n * (-1);
	}
	while (n > 9)
	{
		n = n / 10;
		c++;
	}
	return (c);
}

int ft_find_c_value(int count, int c)
{
	int i;

	i = count - 1;
	while (i > 0)
	{
		c = c * 10;
		i--;
	}
	return (c);
}

int ft_print_negative_sign(int nb)
{
	if (nb < 0)
	{
		nb = nb * (-1);
		ft_putchar('-');
	}
	return (nb);
}

void 	ft_putnbr(int nb)
{
	int	count;
	int	c;
	int	digit;

	if (nb == 0)
		ft_putchar('0');
	else
	{
		count = ft_count_digits(nb);
		c = ft_find_c_value(count, 1);
		nb = ft_print_negative_sign(nb);
		if (count == 1)
		{
			ft_putchar('0' + nb);
			return;
		}
		while (nb > 0)
		{
			digit = nb / c;
			ft_putchar('0' + digit);
			nb = nb - digit * c;
			c = c / 10;
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
}
