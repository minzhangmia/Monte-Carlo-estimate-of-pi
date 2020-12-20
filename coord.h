#pragma once
#include<stdio.h>
#include<stdlib.h>
#include<math.h>
typedef struct Coord
{
	double x, y, radius;
}Coord;

int allocate_memory(Coord** addr, const int N);

void populate_Coord(Coord* const data, const int N);

int hit_or_miss(const Coord pt);

int write_to_files(const Coord* const data, const int N,
				   const int seed, const double mypi);
