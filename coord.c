/**
 * @file	ConsoleApplication1\coord.c.
 * @brief	Coordinate class
 **/
#define _XOPEN_SOURCE 		/* These lines might be needed depending on on your 	*/
#define _XOPEN_SOURCE_EXTENDED 	/* version of compiler in order	to use the functions 	*/
#include "coord.h"

/**
 * @fn	    int allocate_memory(Coord** addr, const int N)
 * @brief	D.Allocate memory
 * @author	ZM
 * @date	2020/11/20
 * @param   [in,out] addr The address where space needs to be allocated.
 * @param 	N The total number of Spaces allocated.
 * @returns	0 normal.
 * 			1 error.
 */
int allocate_memory(Coord** addr, const int N)
{
    return !(*addr = (Coord*)malloc(N * sizeof(Coord)));
}

/**
 * @fn	void populate_Coord(Coord* const data, const int N)
 * @brief	E.Assign values to data
 * @author	ZM
 * @date	2020/11/20
 * @param   [in,out] data Assign values to data.
 * @param 	N The length of the array.
 */
void populate_Coord(Coord* const data, const int N)
{
    for (int i = 0; i < N; i++)
    {
        /** Generates floating point Numbers of 0-1 randomly */
        data[i].x = random() / ((double)RAND_MAX + 0.0);
        data[i].y = random() / ((double)RAND_MAX + 0.0);
        data[i].radius = sqrt(pow(data[i].x, 2)
                            + pow(data[i].y, 2));
    }
}

/**
 * @fn	    int hit_or_miss(const Coord pt)
 * @brief	F.Hit or miss
 * @author	ZM
 * @date	2020/11/20
 * @param 	pt	The structure to be detected.
 * @returns	0 The point is in the unit circle.
 * 			1 The point is outside the unit circle.
 */
int hit_or_miss(const Coord pt)
{
    return pt.radius <= 1;
}

/**
 * @fn	int write_to_files(const Coord* const data, const int N, const int seed, const double mypi)
 * @brief	G.Enter data into a file
 * @author	ZM
 * @date	2020/11/20
 * @param 	data	The target array.
 * @param 	N   	Length of array.
 * @param 	seed	The seed.
 * @param 	mypi	The estimate of PI.
 * @returns	0 Normal.
 * 			1 Error,Failed to open file.
 */
int write_to_files(const Coord* const data, const int N,
                    const int seed, const double mypi)
{
    char file_name[50];
    /** Build file name */
    /**coordinates_N100_Seed1234.txt**/
    sprintf(file_name, "coordinates_N%d_Seed%d.txt", N, seed);
    FILE* fp;
    if ((fp = fopen(file_name, "w")) == NULL) 
    {
        printf("open failed!");
        return 1;
    };
    for (int i = 0; i < N; i++)
    {
        fprintf(fp, "%g %g\n", data[i].x, data[i].y);
    }
    fclose(fp);
    
    /**pi_N100.txt**/
    sprintf(file_name, "pi_N%d.txt", N);
    if ((fp = fopen(file_name, "a")) == NULL) 
    {
        printf("open failed!");
        return 1;
    };
    fprintf(fp, "%lf %d\n", mypi, seed);
    fclose(fp);

    return 0;
}
