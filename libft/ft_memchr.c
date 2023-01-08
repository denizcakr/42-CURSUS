/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ezcakir <ezcakir@student.42kocaeli.com.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/02 16:20:31 by ezcakir           #+#    #+#             */
/*   Updated: 2023/01/02 16:20:32 by ezcakir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
	{
		if (((unsigned char *)s)[i] == (unsigned char)c)
			return ((void *)(s + i));
		i++;
	}
	return (0);
}

// s parametresi ile gösterilen bellek bölgesinin n parametre değeri kadar ilk byte'ına, 
// c parametresi ile gösterilen değerin (unsigned char olarak değerlendirilir) ilk geçtiği yeri arar ve
// bu bellek adresini gösteren bir işaretçi geri döndürür.
// Eğer const void'e atanan parametre 'null' bir işaretçi ise anlamsız sonuç elde edilir.
