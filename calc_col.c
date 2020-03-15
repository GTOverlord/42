/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   calc_col.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: hsillem <hsillem@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/03/10 14:43:46 by hsillem        #+#    #+#                */
/*   Updated: 2020/03/13 20:52:23 by hsillem       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

unsigned int	ft_plane_col(t_object object, t_ray ray)
{
	if (object.distance > 0)
	{
		return (object.color);
	}
	if (ray.loc.x)
		return (0);
	return (0);
}

unsigned int	ft_sphere_col(t_object object, t_ray ray)
{
	if (object.distance > 0)
	{
		return (object.color);
	}
	if (ray.loc.x)
		return (0);
	return (0);
}

unsigned int	ft_cylinder_col(t_object object, t_ray ray)
{
	if (object.distance > 0)
	{
		return (object.color);
	}
	if (ray.loc.x)
		return (0);
	return (0);
}

unsigned int	ft_square_col(t_object object, t_ray ray)
{
	if (object.distance > 0)
	{
		return (object.color);
	}
	if (ray.loc.x)
		return (0);
	return (0);
}

unsigned int	ft_triangle_col(t_object object, t_ray ray)
{
	if (object.distance > 0)
	{
		return (object.color);
	}
	if (ray.loc.x)
		return (0);
	return (0);
}