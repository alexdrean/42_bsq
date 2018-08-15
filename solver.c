// FIXME header

#include "solver.h"
#define getCell(x, y, map) map->tab[x + y * map->width]
#define min(a, b) a < b ? a : b

t_solution *allocate_solution() {
	t_solution *s = malloc(sizeof(t_solution));
	s->len = 0;
	s->x = 0;
	s->y = 0;
	return s;
}

char check_vertical(int x, int y, int len, t_map *map) {
	for (int i = 0; i <= len; i++) {
		if (getCell(x + len, y + i, map))
			return 0;
	}
	return 1;
}
char check_horizontal(int x, int y, int len, t_map *map) {
	void *address = map->tab + x + (y + len) * map->width;
	while (len)
	{
		/*if (len >= 4 && ((int)address & 3) == 0)
		{
			if (*(int *) (address))
				return 0;
			len -= 4;
			address += 4;
		} else {*/
			if (*(char*)address)
				return 0;
			len--;
			address++;
		//}
	}
	return 1;
}

t_solution *solve(t_map *map)
{
	t_solution *sol = allocate_solution();
	for (int y = 0; y < map->width - sol->len; y++) {
		for (int x = 0; x < map->width - sol->len; x++) {
			// For each cell
			int endx = map->width - x;
			int endy = map->height - y;
			int end = min(endx, endy); // Max diagonal distance we can go to
			if (getCell(x, y, map)) continue; // if there's an obstacle
			if (x == 48 && y == 26) {
//				1 + 1;
			}
			for (int i = 1; i <= end; i++) {
				char a = check_vertical(x, y, i, map);
				char b = check_horizontal(x, y, i, map);
				if (!a || !b || i == end)
				{
					if (i > sol->len)
					{
						sol->len = i;
						sol->x = x;
						sol->y = y;
					}
					break;
				}
			}
		}
	}
	return sol;
}
