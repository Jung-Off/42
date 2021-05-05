#include "../includes/ray.h"

void        camera_create(t_cam *cam, t_scene *data)
{
    double aspect_ratio = (double)data->res_x / (double)data->res_y;
 
    cam->viewport_h = 2.0;
    cam->viewport_w = aspect_ratio * cam->viewport_h;
    cam->focal_length = 1.0;

    cam->origin = vdefine(0.0, 0.0, 0.0);
    cam->horizontal = vdefine(cam->viewport_w, 0.0, 0.0);
    cam->vertical = vdefine(0.0, cam->viewport_h, 0.0);

    cam->l_l_corner.x = cam->origin.x - (cam->horizontal.x / 2) 
    - (cam->vertical.x / 2) - 0;
    cam->l_l_corner.y = cam->origin.y - (cam->horizontal.y / 2) 
    - (cam->vertical.y / 2) - 0;
    cam->l_l_corner.z = cam->origin.z - (cam->horizontal.z / 2) 
    - (cam->vertical.z / 2) - cam->focal_length;
}

t_ray       ray_primary(t_cam *cam, double u, double v)
{
    t_ray ray;
    
    ray.orig = cam->origin;

    //ray.dir = vunit((vsubstract(vadd(vadd(cam->l_l_corner, vscalarmul(cam->horizontal, u)), vscalarmul(cam->vertical, v)), cam->origin)));
    ray.dir.x = cam->l_l_corner.x + u*cam->horizontal.x + v*cam->vertical.x
            - cam->origin.x;
    ray.dir.y = cam->l_l_corner.y + u*cam->horizontal.y + v*cam->vertical.y
            - cam->origin.y;
    ray.dir.z = cam->l_l_corner.z + u*cam->horizontal.z + v*cam->vertical.z
            - cam->origin.z;
    ray.dir = vunit(ray.dir);
    return (ray);
}

t_p3 ray_color(t_ray *r)
{
    //ray = vdefine(255, 0, 0);
    double t;

    t = 0.5 * (r->dir.y + 1.0);

    //return(ray);
    return (vadd(vscalarmul(vdefine(1,1,1), 1.0 - t) , vscalarmul(vdefine(0.5, 0.7, 1.0), t)));
}

void make_picture(t_mlx *mlx, t_scene data, t_fig *lst)
{
    t_ray ray;
    t_p3 color;
    
    int y = 0;
    int x;
    double u , v;
    while (y < data.res_y)
    {
        x = 0;
        while(x < data.res_x)
        {
            u = (double)x / (data.res_x - 1);
            v = (data.res_y - (double)y - 1) / (data.res_y - 1);
            ray = ray_primary(mlx->cam, u, v);
            color = ray_color(&ray);

            color.x = (int)(color.x * 255);
            color.y = (int)(color.y * 255);
            color.z = (int)(color.z * 255);
            mlx->data[y * data.res_x + x] = mlx_get_color_value(mlx->mlx_ptr, color.x * 256 * 256 + color.y * 256 + color.z);
             ++x;
        }
        ++y;
    }

}
