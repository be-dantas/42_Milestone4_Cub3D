#include "../../includes/cub3d.h"

void draw_map(char **map, int i, int j, t_access *access)
{
    int x;
    int y;
    int start_x;
    int start_y;
    char *px;

    start_y = i * 64; 
    while (map[i][j])
    {
        start_x = j * 64;
        y = start_y;
        while (y < start_y + 64)
        {
            x = start_x;
            while (x < start_x + 64)
            {
                px = access->img_pointer + (y * access->line_len + x
                        * (access->bits_per_pixel / 8));
                if (map[i][j] == '1')
                    *(unsigned int *)px = 0xFFFFFF;
                else if (map[i][j] == '0')
                    *(unsigned int *)px = 0x000000;
                
                x++;
            }
            y++;
        }
        j++;
    }
}
