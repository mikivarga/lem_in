/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvarga <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/01 17:29:08 by mvarga            #+#    #+#             */
/*   Updated: 2016/12/01 17:34:48 by mvarga           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/libft.h"

void		ft_putstr_fd(char const *s, int fd)
{
	if (s)
	{
		while (*s)
			ft_putchar_fd(*s++, fd);
	}
}
