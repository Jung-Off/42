
#include "../includes/main.h"


int main(int argc, char **argv)
{
	t_mlx 	mlx;
	t_scene data;
	t_fig	*lst;

	//
	t_fig 	*start;
	start = lst;
	parse(&mlx, &data, &lst, argv);

	printf("--------R--------\n");
	printf("[x :%d y :%d] ex :%d \n", data.res_x, data.res_y, data.res_ex);
	
	printf("--------amb---------\n");
	printf("ratio :%lf color :%x ex :%d\n", data.amb_ratio, data.amb_color, data.amb_ex);

	printf("---------l----------\n");
	while(data.l)
	{
		printf("[x :%lf y :%lf z :%lf]  br : %lf color : %x\n", data.l->position.x, data.l->position.y, data.l->position.z,  data.l->br, data.l->color);
	data.l = data.l->next;	
	}

	printf("----------cam-------\n");
	while(mlx.cam)
	{
		printf("position[%lf, %lf, %lf], dir_vec[%lf, %lf, %lf], fov %d\n\n", mlx.cam->position.x, mlx.cam->position.y, mlx.cam->position.z, mlx.cam->dir_vec.x, mlx.cam->dir_vec.y, mlx.cam->dir_vec.z, mlx.cam->fov);
		mlx.cam = mlx.cam->next;
	}

	while(lst)
	{
		printf("--------------------");
		printf("\n\nsp : x :%lf, y :%lf, z :%lf, r :%lf color :%x\n", lst->fig.sp.c.x, lst->fig.sp.c.y, lst->fig.sp.c.z, lst->fig.sp.r, lst->color);
		
		printf("pl : x : %lf, y : %lf, z : %lf n [x: %lf, y %lf, z %lf] color :%x\n", lst->fig.pl.position.x ,lst->fig.pl.position.y , lst->fig.pl.position.z , lst->fig.pl.normal.x ,lst->fig.pl.normal.y, lst->fig.pl.normal.z, lst->fig.pl.color);
		
		printf("sq : x: %lf, y : %lf, z :%lf n x: %lf, y: %lf, z :%lf length :%lf col : %x\n", lst->fig.sq.sq_c.x, lst->fig.sq.sq_c.y, lst->fig.sq.sq_c.z, lst->fig.sq.normal.x, lst->fig.sq.normal.y, lst->fig.sq.normal.z, lst->fig.sq.length, lst->fig.sq.color);
	
		printf("cy : %lf, %lf, %lf normal : %lf %lf %lf r : %lf h : %lf color : %x\n", lst->fig.cy.c.x, lst->fig.cy.c.y, lst->fig.cy.c.z, lst->fig.cy.normal.x, lst->fig.cy.normal.y, lst->fig.cy.normal.z, lst->fig.cy.r, lst->fig.cy.h, lst->fig.cy.color);

		printf("tr 1: %lf %lf %lf 2: %lf %lf %lf 3: %lf %lf %lf color : %x\n\n", lst->fig.tr.first.x, lst->fig.tr.first.y, lst->fig.tr.first.z, lst->fig.tr.second.x, lst->fig.tr.second.y, lst->fig.tr.second.z, lst->fig.tr.third.x, lst->fig.tr.third.y, lst->fig.tr.third.z, lst->fig.tr.color);
		lst = lst->next;	
	}

}
