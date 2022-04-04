/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymaragre <ymaragre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/17 13:53:41 by ymaragre          #+#    #+#             */
/*   Updated: 2022/03/19 10:06:58 by ymaragre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

static int	ft_numlen(int n);
static int	ft_abs(int n);

char	*ft_itoa(int n)
{
	char	*str;
	int		len;
	int		i;

	len = ft_numlen(n);
	str = (char *) malloc(len + 1);
	if (!str)
		return ((char *) 0);
	if (n == 0)
		str[0] = '0';
	if (n < 0)
		str[0] = '-';
	i = 0;
	while (n)
	{
		str[len - ++i] = ft_abs(n % 10) + 48;
		n /= 10;
	}
	str[len] = '\0';
	return (str);
}

static int	ft_numlen(int n)
{
	int	i;

	if (n > 0)
		i = 0;
	else
		i = 1;
	while (n)
	{
		i++;
		n /= 10;
	}
	return (i);
}

static int	ft_abs(int n)
{
	if (n >= 0)
		return (n);
	else
		return ((-1) * n);
}
