#include <limits>
#include "CountMinSketch.h"
#include "HashFunctions.h"

/**
 * Implement increment() correctly
 */
void CountMinSketch::increment(const string & s) {
    /* YOUR CODE HERE */
    for(auto const & iter : hash_functions){
        //count[hash_functions][iter(s) % M];
        int index = iter(s) % M;
        count[hash_functions][index] += 1;
    }
}

/**
 * Implement find() correctly
 */
unsigned int CountMinSketch::find(const string & s) {
    /* YOUR CODE HERE */
}
