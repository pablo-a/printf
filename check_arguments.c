/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_arguments.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pabril <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/13 12:39:37 by pabril            #+#    #+#             */
/*   Updated: 2016/03/17 11:46:26 by pabril           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"

int		ft_check_flags(const char *str, int i, t_list **lst)
{
	int nb;

	nb = 0;
	while (str[i] == ' ' || str[i] == '#' || str[i] == '-' || str[i] == '+'
			|| str[i] == '0')
	{
		if (str[i] == ' ')
			(*lst)->blanck = TRUE;
		else if (str[i] == '#')
			(*lst)->diese = TRUE;
		else if (str[i] == '-')
			(*lst)->minus = TRUE;
		else if (str[i] == '+')
			(*lst)->plus = TRUE;
		else if (str[i] == '0')
			(*lst)->zero = TRUE;
		i++;
		nb++;
	}
	return (nb);
}

int		ft_check_lenght(const char *str, int i, int *result)
{
	int size;

	size = 0;
	*result = ft_atoi(str + i);
	while (ft_isdigit(str[i]))
	{
		size++;
		i++;
	}
	return (size);
}

int		ft_check_precision(const char *str, int i, t_list **lst)
{
	int		nb;

	nb = 0;
	if (str[i] == '.')
	{
		i++;
		nb++;
		(*lst)->modified_precision = 1;
		if (!ft_isdigit(str[i]))
			return (nb);
		(*lst)->precision = ft_atoi(str + i);
		while (ft_isdigit(str[i]))
		{
			i++;
			nb++;
		}
	}
	else
		return (0);
	return (nb);
}

int		ft_check_modifiers(const char *str, int i, t_list **lst)
{
	if (str[i] == 'h' && str[i + 1] == 'h')
		(*lst)->hh = TRUE;
	else if (str[i] == 'l' && str[i + 1] == 'l')
		(*lst)->ll = TRUE;
	else if (str[i] == 'h')
		(*lst)->h = TRUE;
	else if (str[i] == 'l')
		(*lst)->l = TRUE;
	else if (str[i] == 'j')
		(*lst)->j = TRUE;
	else if (str[i] == 'z')
		(*lst)->z = TRUE;
	if ((*lst)->hh || (*lst)->ll)
		return (2);
	if ((*lst)->l || (*lst)->h || (*lst)->j || (*lst)->z)
		return (1);
	return (0);
}

int		ft_check_type(const char *str, int i, char *c)
{
	*c = str[i];
	return (1);
}
