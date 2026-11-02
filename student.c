#include "student.h"
#include <stdlib.h>
#include <mpi.h>

static double get_rand_minus_one_one(void) {
    return 2 * (rand() / (double)RAND_MAX) - 1;
}

/* Replace this sequential baseline with an MPI implementation.
 * num_tosses is the total number of tosses across all ranks.
 * MPI is already initialized; rank 0 prints the returned estimate.
 */
double estimate_pi(int num_tosses, int rank, int size) {
    (void)rank;
    (void)size;
    int num_hits = 0;
    for (int toss = 0; toss < num_tosses; toss++) {
        double x = get_rand_minus_one_one();
        double y = get_rand_minus_one_one();
        if (x*x + y*y <= 1) {
            num_hits++;
        }
    }
    return 4.0 * num_hits / (double)num_tosses;
}
