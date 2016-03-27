/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_number_case.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pabril <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/02 14:50:36 by pabril            #+#    #+#             */
/*   Updated: 2016/03/27 10:56:46 by pabril           ###   ########.fr       */
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
		a = (long long int)va_arg(*ap, long);
	else if (lst->ll)
		a = va_arg(*ap, long long int);
	else if (lst->j)
		a = (long long int)va_arg(*ap, intmax_t);
	else if (lst->z)
		a = (long long int)va_arg(*ap, size_t);
	else if (lst->hh)
		a = (long long)(char)va_arg(*ap, int);
	else if (lst->h)
		a = (long long)(short int)va_arg(*ap, int);
	else
		a = (long long int)va_arg(*ap, int);
	return (a);
}

unsigned long long	ft_get_unsigned_nb(t_list *lst, unsigned long long b,
		va_list *ap)
{
	if (lst->l || lst->type == 'U' || lst->type == 'O')
		b = (unsigned long long)va_arg(*ap, unsigned long int);
	else if (lst->ll)
		b = va_arg(*ap, unsigned long long);
	else if (lst->j)
		b = (unsigned long long)va_arg(*ap, uintmax_t);
	else if (lst->z)
		b = (unsigned long long)va_arg(*ap, size_t);
	else if (lst->hh)
		b = (unsigned long long)(unsigned char)va_arg(*ap, unsigned int);
	else if (lst->h)
		b = (unsigned long long)(unsigned short int)va_arg(*ap, unsigned int);
	else
		b = (unsigned long long)va_arg(*ap, unsigned int);
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
