/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   calc_dist.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: hsillem <hsillem@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/03/10 14:41:36 by hsillem        #+#    #+#                */
/*   Updated: 2020/03/13 20:53:57 by hsillem       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"
#include <math.h>

double		ft_plane_dist(t_object object, t_ray ray)
{
	if (object.color && ray.dir.x)
		return (0);
	return (0);
}

double		ft_sphere_dist(t_object object, t_ray ray)
{
	double	a;
	double	b;
	double	c;
	double	dis;
	double	result1;
	double	result2;

	a = ft_dot(ray.dir, ray.dir);
	b = 2 * ft_dot(ray.dir, ft_subs(ray.loc, object.loc));
	c = ft_dot(ft_subs(ray.loc, object.loc), ft_subs(ray.loc, object.loc)) - pow(object.parameters[0], 2);
	dis = pow(b, 2) - 4 * a * c;
	if (dis < 0)
		return (0);
	result1 = (-b - sqrt(dis)) / (2 * a);
	result2 = (-b + sqrt(dis)) / (2 * a);
	if (result1 > 0 && result1 < result2)
		return (result1);
	else if (result2 > 0)
		return (result2);
	return (0);
}

double		ft_cylinder_dist(t_object object, t_ray ray)
{
	if (object.color && ray.dir.x)
		return (0);
	return (0);
}

double		ft_square_dist(t_object object, t_ray ray)
{
	if (object.color && ray.dir.x)
		return (0);
	return (0);
}

double		ft_triangle_dist(t_object object, t_ray ray)
{
	if (object.color && ray.dir.x)
		return (0);
	return (0);
}