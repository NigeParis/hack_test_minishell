/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vec_at.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoulard <bgoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 16:03:56 by bgoulard          #+#    #+#             */
/*   Updated: 2024/06/22 08:21:42 by bgoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_vector.h"

// return elem n
void	*ft_vec_at(t_vector *vec, size_t n)
{
	if (vec == NULL || vec->datas == NULL || vec->count < n)
		return (NULL);
	return (vec->datas[n]);
}
