#ifndef HEADER_H
# define HEADER_H

# ifndef M_PI
#  define M_PI 3.14159265358979323846
#  endif


typedef struct	s_img
{
	void		*img;
	char		*addr;
	int			bits_per_pixel;
	int			line_length;
	int			endian;
}				t_img;

typedef struct	s_vec
{
	double	x;
	double	y;
	double	z;
}				t_vec;

typedef union 	s_col
{
	unsigned int	whole;
	struct			colors
	{
		unsigned char	t;
		unsigned char	g;
		unsigned char	r;
		unsigned char	b;
	}				colors;
}				t_col;

typedef struct	s_object
{
	double	distance;
	t_vec	loc;
	double	parameters[1];
	int		shape;
	unsigned int	color;
}				t_object;

typedef struct	s_window
{
	void	*mlx;
	void	*mlx_win;
}				t_window;

typedef struct	s_ray
{
	t_vec	loc;
	t_vec	dir;
	double	tork;
}				t_ray;

typedef struct	s_light
{
	t_vec	loc;
	t_col	col;
}				t_light;

typedef struct	s_matrix
{
	t_vec	v0;
	t_vec	v1;
	t_vec	v2;
}				t_matrix;

void			ft_get_img(t_ray camera, t_object *objects, t_img *img);
void			ft_put_pixel(t_img *img, int x, int y, unsigned int color);
int				ft_exit_esc(int key, t_window *win);
t_vec			ft_normalize(t_vec vec);
t_vec			ft_add(t_vec v1, t_vec v2);
t_vec			ft_subs(t_vec v1, t_vec v2);
double			ft_dot(t_vec v1, t_vec v2);
double			ft_plane_dist(t_object object, t_ray ray);
double			ft_sphere_dist(t_object object, t_ray ray);
double			ft_cylinder_dist(t_object object, t_ray ray);
double			ft_square_dist(t_object object, t_ray ray);
double			ft_triangle_dist(t_object object, t_ray ray);
unsigned int	ft_plane_col(t_object object, t_ray ray);
unsigned int	ft_sphere_col(t_object object, t_ray ray);
unsigned int	ft_cylinder_col(t_object object, t_ray ray);
unsigned int	ft_square_col(t_object object, t_ray ray);
unsigned int	ft_triangle_col(t_object object, t_ray ray);

#endif