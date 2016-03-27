/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_number_case.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pabril <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/02 14:50:36 by pabril            #+#    #+#             */
/*   Updated: 2016/03/27 14:34:00 by pabril           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"

int					ft_putnbr_signed(long long int n)
{
	if (n < 0)
	{
		n *= -1;
		ft_print_number((unsigned long long int)n);
		return (ft_len_number(n));
	}
	else
	{
		ft_print_number((unsigned long long int)n);
		return (ft_len_number(n));
	}
}

long long			ft_get_signed_number(t_list *lst, long long a, va_list *ap)
{
	if (lst->l || lst->type == 'D')
		a = (long int)va_arg(*ap, long long int);
	else if (lst->ll)
		a = va_arg(*ap, long long int);
	else if (lst->j)
		a = (intmax_t)va_arg(*ap, long long int);
	else if (lst->z)
		a = (size_t)va_arg(*ap, long long int);
	else if (lst->hh)
		a = (char)va_arg(*ap, long long int);
	else if (lst->h)
		a = (short int)va_arg(*ap, long long int);
	else
		a = (int)va_arg(*ap, long long int);
	return (a);
}

unsigned long long	ft_get_unsigned_nb(t_list *lst, unsigned long long b,
		va_list *ap)
{
	if (lst->l || lst->type == 'U' || lst->type == 'O')
		b = (unsigned long int)va_arg(*ap, unsigned long long int);
	else if (lst->ll)
		b = va_arg(*ap, unsigned long long int);
	else if (lst->j)
		b = (uintmax_t)va_arg(*ap, unsigned long long);
	else if (lst->z)
		b = (size_t)va_arg(*ap, unsigned long long);
	else if (lst->hh)
		b = (unsigned char)va_arg(*ap, unsigned long long int);
	else if (lst->h)
		b = (unsigned short int)va_arg(*ap, unsigned long long int);
	else
		b = (unsigned int)va_arg(*ap, unsigned long long int);
	return (b);
}

int					ft_number_case(t_list *lst, va_list *ap)
{
	signed long long int	a;
	unsigned long long int	b;
	char					c;

	c = lst->type;
	a = 0;
	b = 0;
	if (c == 'd' || c == 'i' || c == 'D')
	{
		a = ft_get_signed_number(lst, a, ap);
		ft_handle_signed(a, lst);
	}
	else if (c == 'u' || c == 'x' || c == 'X' || c == 'U' || c == 'o'
			|| c == 'O')
	{
		b = ft_get_unsigned_nb(lst, b, ap);
		ft_handle_unsigned(b, lst);
	}
	return (0);
}
