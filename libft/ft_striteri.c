/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ezcakir <ezcakir@student.42kocaeli.com.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/02 16:19:08 by ezcakir           #+#    #+#             */
/*   Updated: 2023/01/02 16:19:10 by ezcakir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_striteri(char *s, void (*f)(unsigned int, char *))
{
	unsigned int	i;

	if (s)
	{
		i = 0;
		while (s[i])
		{
			f(i, &s[i]);
			i++;
		}
	}
}

//karakterin indeksini ilk arguman olarak gönderip, f fonksiyonunu s stringinin
//bütün karakterlerine uygular. (s stringindeki her karakterin adresine tek tek f fonksiyonu uygulanır).

// #include <stdio.h>

// void	ft_42(unsigned int a, char *c)
// {
// 	*c = ft_toupper(*c);
// }
// int main()
// {
// 	char str[] = "Deniz";
// 	ft_striteri(str, ft_42);
// 	printf("%s", str);
// }
