#include "./includes/cub3d.h"

int main()
{
    t_access access;

    access.mlx_connection = mlx_init();

    access.mlx_window = mlx_new_window
    (
        access.mlx_connection,
        WIDTH,
        HEIGHT,
        "Cub3D - wedos-sa & bedantas"
    );
    
    mlx_loop(access.mlx_connection);
    return (0);
}