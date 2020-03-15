/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: hsillem <hsillem@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/02/04 15:21:00 by hsillem        #+#    #+#                */
/*   Updated: 2020/03/13 20:54:33 by hsillem       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "minilibx/mlx.h"
#include "header.h"
#include <stdio.h>

int     main(void)
{
	t_window	mlx;
	t_img   	img;
	t_ray		cam;
	t_object	objects[5];

	cam = (t_ray){};
	cam.loc.y = 0;
	cam.loc.z = 0;
	cam.dir.y = 0;
	cam.dir.z = 1;
	cam.dir = ft_normalize(cam.dir);
	printf("dir.y: %f\ndir.z: %f\n", cam.dir.y, cam.dir.z);
	objects[0] = (t_object){};
	objects[1] = (t_object){};
	objects[2] = (t_object){};
	objects[3] = (t_object){};
	objects[4] = (t_object){};
	objects[0].color = 0x00ff007f;
	objects[0].loc.x = 2.25;
	objects[0].loc.z = 50;
	objects[0].parameters[0] = 3;
	objects[0].shape = 1;
	objects[1].color = 0x00ff007f;
	objects[1].loc.x = -2.25;
	objects[1].loc.z = 50;
	objects[1].parameters[0] = 3;
	objects[1].shape = 1;
	objects[2].color = 0x00ff7f00;
	objects[2].loc.x = 1.8;
	objects[2].loc.z = 40;
	objects[2].parameters[0] = .5;
	objects[2].shape = 1;
	objects[3].color = 0x00ff7f00;
	objects[3].loc.x = -1.8;
	objects[3].loc.z = 40;
	objects[3].parameters[0] = .5;
	objects[3].shape = 1;
	objects[4].shape = -1;
	mlx.mlx = mlx_init();
	mlx.mlx_win = mlx_new_window(mlx.mlx, 1920, 1080, "test");
	img.img = mlx_new_image(mlx.mlx, 1920, 1080);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length, &img.endian);
	ft_get_img(cam, objects, &img);
	mlx_put_image_to_window(mlx.mlx, mlx.mlx_win, img.img, 0, 0);
	mlx_key_hook(mlx.mlx_win, ft_exit_esc, &mlx);
	mlx_loop(mlx.mlx);
	return (0);
}
