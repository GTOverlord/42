/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   math.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: hsillem <hsillem@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/03/10 14:32:54 by hsillem        #+#    #+#                */
/*   Updated: 2020/03/13 20:51:10 by hsillem       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"
#include <math.h>

t_vec	ft_normalize(t_vec vec)
{
	t_vec	result;
	double	product;

	result = vec;
	product = sqrt(pow(result.x, 2) + pow(result.y, 2) + pow(result.z, 2));
	result.x /= product;
	result.y /= product;
	result.z /= product;
	return (result);
}

t_vec		ft_add(t_vec v1, t_vec v2)
{
	t_vec	result;

	result.x = v1.x + v2.x;
	result.y = v1.y + v2.y;
	result.z = v1.z + v2.z;
	return (result);
}

t_vec		ft_subs(t_vec v1, t_vec v2)
{
	t_vec	result;

	result.x = v1.x - v2.x;
	result.y = v1.y - v2.y;
	result.z = v1.z - v2.z;
	return (result);
}

double		ft_dot(t_vec v1, t_vec v2)
{
	return (v1.x * v2.x + v1.y * v2.y + v1.z * v2.z);
}