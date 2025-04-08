/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_toupper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbouteil <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 10:31:20 by fbouteil          #+#    #+#             */
/*   Updated: 2024/11/14 11:11:19 by fbouteil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_toupper(int c)
{
	if (c >= -128 && c <= -2)
		c += 256;
	if (c >= 'a' && c <= 'z')
		return (c - 32);
	return (c);
}
