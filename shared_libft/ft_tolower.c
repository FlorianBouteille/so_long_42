/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tolower.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbouteil <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 10:37:06 by fbouteil          #+#    #+#             */
/*   Updated: 2024/11/14 11:09:37 by fbouteil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_tolower(int c)
{
	if (c >= -128 && c <= -2)
		c += 256;
	if (c >= 'A' && c <= 'Z')
		return (c + 32);
	return (c);
}
