/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_elements.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbuisser <hbuisser@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/04 15:08:53 by hbuisser          #+#    #+#             */
/*   Updated: 2020/02/05 15:59:26 by hbuisser         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"

void get_floor_color(t_index *idx)
{
    int i;
    int digit;

    i = 1;
    digit = 0;
    while (idx->el->elem[idx->el->floor_line][i] == ' ')
		i++;
    while (idx->el->elem[idx->el->floor_line][i] >= '0' &&
            idx->el->elem[idx->el->floor_line][i] <= '9')
    {
        digit = (digit * 10) + idx->el->elem[idx->el->floor_line][i] - '0';
        i++;
    }
    idx->el->floor_color.rgb.r = digit;
    printf("%i\n", idx->el->floor_color.rgb.r);
    i++;
    digit = 0;
    while (idx->el->elem[idx->el->floor_line][i] >= '0' &&
            idx->el->elem[idx->el->floor_line][i] <= '9')
    {
        digit = (digit * 10) + idx->el->elem[idx->el->floor_line][i] - '0';
        i++;
    }
    idx->el->floor_color.rgb.g = digit;
    printf("%i\n", idx->el->floor_color.rgb.g);
    i++;
    digit = 0;
    while (idx->el->elem[idx->el->floor_line][i] >= '0' &&
            idx->el->elem[idx->el->floor_line][i] <= '9')
    {
        digit = (digit * 10) + idx->el->elem[idx->el->floor_line][i] - '0';
        i++;
    }
    idx->el->floor_color.rgb.b = digit;
    printf("%i\n", idx->el->floor_color.rgb.b);
}

void get_resolution(t_index *idx)
{
    int	i;
	int	digit;

	digit = 0;
    i = 1;
    while (idx->el->elem[idx->el->resolution_line][i] == ' ')
		i++;
    while (idx->el->elem[idx->el->resolution_line][i] >= '0' &&
            idx->el->elem[idx->el->resolution_line][i] <= '9')
    {
        digit = (digit * 10) + idx->el->elem[idx->el->resolution_line][i] - '0';
        i++;
    }
    idx->el->resolution_x = digit;
    digit = 0;
    while (idx->el->elem[idx->el->resolution_line][i] == ' ')
		i++;
    while (idx->el->elem[idx->el->resolution_line][i] >= '0' &&
            idx->el->elem[idx->el->resolution_line][i] <= '9')
    {
        digit = (digit * 10) + idx->el->elem[idx->el->resolution_line][i] - '0';
        i++;
    }
    idx->el->resolution_y = digit;
}

void create_elements(t_index *idx)
{
    int i;
    int j;

    i = 0;
    j = 0;
    idx->el->elem = ft_split(idx->parse->data, '\n');
    while (idx->el->elem[i] != NULL)
    {
        j = 0;
        while (idx->el->elem[i][j] != '\0')
        {
            if (idx->el->elem[i][j] == 'R')
                idx->el->resolution_line = i;
            else if (idx->el->elem[i][j] == 'N')
                idx->el->north_line = i;
            else if (idx->el->elem[i][j] == 'S')
            {
                if (idx->el->elem[i][j + 1] == 'O')
                    idx->el->south_line = i;
                else
                    idx->el->sprite_line = i;
            }
            else if (idx->el->elem[i][j] == 'W')
                idx->el->west_line = i;
            else if (idx->el->elem[i][j] == 'E')
                idx->el->east_line = i;
            else if (idx->el->elem[i][j] == 'F')
                idx->el->floor_line = i;
            else if (idx->el->elem[i][j] == 'C')
                idx->el->ceilling_line = i;
            j++;
        }
        i++;
    }
    get_resolution(idx);
    get_floor_color(idx);
    i = 0;
    while (i < 8)
	{
		printf("%s\n", *idx->el->elem);
		idx->el->elem++;
		i++;
	}
}
