/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvarga <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/26 16:33:04 by mvarga            #+#    #+#             */
/*   Updated: 2016/12/01 20:55:35 by mvarga           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/libft.h"

void		*ft_memcpy(void *dst, const void *src, size_t n)
{
	char		*d;
	const char	*s;

	s = src;
	d = dst;
	while (n--)
	{
		*d++ = *s++;
	}
	return (dst);
}
