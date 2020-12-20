/**
 * \file    assignment4.c
 * \brief   Calculate a MC estimate of PI by geneating random points in the 2D unit square.
 * \author  ZM
 * \date    2020-11-17
 */

#define _XOPEN_SOURCE 		/* These lines might be needed depending on on your 	*/
#define _XOPEN_SOURCE_EXTENDED 	/* version of compiler in order	to use the functions 	*/
 /* random() & srandom(). If you need these lines here, 	*/
 /* you will also need them in your file coord.c 	*/

#include "coord.h" 		/* Note the use of quotes rather than angle brackets 	*/
#include <stdio.h>
#include <stdlib.h>

/* Function prototypes */
int read_from_stdin(int* const N_p, int* const seed_p);
int allocate_memory(Coord** addr, const int N);
void populate_Coord(Coord* const data, const int N);
int hit_or_miss(const Coord pt);
int write_to_files(const Coord* const data, const int N, const int seed, const double mypi);

int main(void)
{
    Coord* coordinates;
    int num_points, seed;

    /*
     * Read user input values from command line
     */
    if (read_from_stdin(&num_points, &seed) != 0) 
    {
        fprintf(stderr, "Error calling read_from_stdin\n");
        return(EXIT_FAILURE);
    }

    srandom(seed);  		/* Seed PRNG random() 					*/

    /*adding
     * Allocate memory for array of structs
     * ADD SOME ERROR CHECKING BELOW. CHECK THE RETURN VALUE OF THE 
     * FUNCTION SIMILAR TO WHAT WE HAVE FOR read_from_stdin() ABOVE 
     */
    if (allocate_memory(&coordinates, num_points) != 0) {
        fprintf(stderr, "Error calling allocate_memory\n");
        return(EXIT_FAILURE);
    }

    /*
     * populate members of elements of the array using a PRNG
     */
    populate_Coord(coordinates, num_points);

    /*
     * Calculate estimate of PI
     */
    int count = 0;
    double mypi;
    

    /*adding
    * STUDENTS MUST INSERT CODE HERE TO ESTIMATE PI 
    * PLEASE USE THE VARIABLES count AND mypi ABOVE.
    * mypi SHOULD HOLD YOUR ESTIMATE.
    * USE THE FUNCTION hit_or_miss WHICH YOU WROTE 
    */
    for (int i = 0; i < num_points; count += hit_or_miss(coordinates[i++]));
    mypi = 4.0 * (double)count / (double)num_points;

    printf("Estimate of pi = %lf\n", mypi);

    /*
     * Write generated coordinates to a file. Create filename according to input values
     */
    if (write_to_files(coordinates, num_points, seed, mypi) != 0) {
        fprintf(stderr, "Error calling write_to_file\n");
        return(EXIT_FAILURE);
    }
    free(coordinates); 		/* Free allocated memory to get into good habits! 	*/
    return 0;
}
