/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   image_utils.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: hsillem <hsillem@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/02/02 20:26:50 by hsillem        #+#    #+#                */
/*   Updated: 2020/03/13 20:50:29 by hsillem       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"
#include <stdlib.h>
#include "minilibx/mlx.h"
#include <math.h>
#include <unistd.h>
#include <stdio.h>

void	ft_put_pixel(t_img *img, int x, int y, unsigned int color)
{
	*(unsigned int*)(img->addr + x * (img->bits_per_pixel / 8) 
	+ y * img->line_length) = color;
}

void	print_loc(t_vec loc)
{
	printf("location:  x: %14f, y: %14f, z: %14f\n", loc.x, loc.y, loc.z);
}

void	print_dir(t_vec dir)
{
	printf("direction: x: %14f, y: %14f, z: %14f\n", dir.x, dir.y, dir.z);
}

t_ray	ft_get_ray(t_vec loc1, t_vec loc2)
{
	t_ray	result;

	result.loc = loc1;
	result.dir = ft_subs(loc1, loc2);
	result.dir = ft_normalize(result.dir);
	return (result);
}

double	ft_jump_dist(t_object object, t_ray ray)
{
	double	(*functions[5])(t_object, t_ray);

	functions[0] = ft_plane_dist;
	functions[1] = ft_sphere_dist;
	functions[2] = ft_cylinder_dist;
	functions[3] = ft_square_dist;
	functions[4] = ft_triangle_dist;
	return (functions[object.shape](object, ray));
}

unsigned int	ft_jump_col(t_object object, t_ray ray)
{
	unsigned int	(*functions[5])(t_object, t_ray);

	functions[0] = ft_plane_col;
	functions[1] = ft_sphere_col;
	functions[2] = ft_cylinder_col;
	functions[3] = ft_square_col;
	functions[4] = ft_triangle_col;
	return (functions[object.shape])(object, ray);
}

unsigned int	ft_ray_trace(t_object *objects, t_ray ray)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (objects[i].shape != -1)
	{
		objects[i].distance = ft_jump_dist(objects[i], ray);
		if ((objects[i].distance < objects[j].distance || !objects[j].distance) && objects[i].distance > 0)
			j = i;
		i++;
	}
	if (objects[j].distance <= 0)
		return (0x0);
	return (ft_jump_col(objects[j], ray));
}

t_vec	ft_get_loc(t_ray ray, double dist)
{
	t_vec result;

	result = ray.loc;
	result.x += ray.dir.x * dist;
	result.y += ray.dir.y * dist;
	result.z += ray.dir.z * dist;
	return (result);
}

t_vec	ft_rotate(t_vec vec, t_matrix matrix)
{
	t_vec	result;

	result.x = vec.x * matrix.v0.x + vec.y * matrix.v1.x + vec.z * matrix.v2.x;
	result.y = vec.x * matrix.v0.y + vec.y * matrix.v1.y + vec.z * matrix.v2.y;
	result.z = vec.x * matrix.v0.z + vec.y * matrix.v1.z + vec.z * matrix.v2.z;
	return (result);
}

t_matrix	ft_get_matrix(t_vec axis)
{
	t_matrix	result;
	
	result.v0.x = 1;
	result.v0.y = -1 * axis.z;
	result.v0.z = axis.y;
	result.v1.x = axis.z;
	result.v1.y = 1;
	result.v1.z = -1 * axis.x;
	result.v2.x = -1 * axis.y;
	result.v2.y = axis.x;
	result.v2.z = 1;
	return (result);
}

t_vec	ft_get_grid(t_ray camera, int x, int y, double pixelsize)
{
//	print_dir(camera.dir);
	camera.loc = ft_get_loc(camera, 1);
//	print_loc(camera.loc);
	camera.dir = ft_rotate(camera.dir, (t_matrix){{0, 0, -1}, {0, -1, 0}, {1, 0, 0}});
//	print_dir(camera.dir);
	camera.loc = ft_get_loc(camera, x * pixelsize);
//	print_loc(camera.loc);
	camera.dir = ft_rotate(camera.dir, (t_matrix){{0, 1, 0}, {-1, 0, 0}, {0, 0, -1}});
//	print_dir(camera.dir);
	camera.loc = ft_get_loc(camera, y * pixelsize);
//	write(1, "\n", 1);
	return (camera.loc);
}

void	ft_get_img(t_ray camera, t_object *objects, t_img *img)
{
	int x;
	int y;

	y = -540;
	while (y < 540)
	{
		x = -960;
		while (x < 960)
		{
			ft_put_pixel(img, x + 960, y + 540, ft_ray_trace(objects, ft_get_ray(camera.loc, ft_get_grid(camera, x, y, 1.0 / 1920))));
			x++;
		}
		y++;
	}
}

int		ft_exit_esc(int key, t_window *win)
{
	if (key == 53)
	{
		mlx_destroy_window(win->mlx, win->mlx_win);
		exit(0);
	}
	return (0);
}
