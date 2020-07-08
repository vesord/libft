/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matrus <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/03 21:39:47 by matrus            #+#    #+#             */
/*   Updated: 2020/05/08 21:40:23 by matrus           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_ilen(int nb)
{
	if (nb < 0)
	{
		if (nb > -10)
			return (2);
		else
			return (ft_ilen(nb / 10 * -1) + 2);
	}
	if (nb < 10)
		return (1);
	return (ft_ilen(nb / 10) + 1);
}

char		*ft_itoa(int n)
{
	int		ilen;
	char	*str;

	ilen = ft_ilen(n);
	str = (char*)ft_calloc(ilen + 1, sizeof(*str));
	if (!str)
		return (NULL);
	str[ilen] = 0;
	if (n < 0)
		str[0] = '-';
	while (ilen && str[ilen - 1] != '-')
	{
		if (n < 0)
			str[--ilen] = n % 10 * -1 + '0';
		else
			str[--ilen] = n % 10 + '0';
		n /= 10;
	}
	return (str);
}
