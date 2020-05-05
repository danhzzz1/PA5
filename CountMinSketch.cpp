#include <limits>
#include "CountMinSketch.h"
#include "HashFunctions.h"

/**
 * Implement increment() correctly
 */
void CountMinSketch::increment(const string & s) {
    /* YOUR CODE HERE */
    unsigned int counter = 0;
    for(auto const & iter : hash_functions){
        //count[hash_functions][iter(s) % M];
        if(counter < K){
            count[counter][iter(s)%M] += 1;
            counter++;
        }
    }
}

/**
 * Implement find() correctly
 */
unsigned int CountMinSketch::find(const string & s) {
    /* YOUR CODE HERE */
    unsigned int est = -1;
    unsigned int curr = 0;
    unsigned int counter = 0;
    for(auto const & iter : hash_functions){
        unsigned int index  = iter(s) % M;
        if(counter < K){
            curr = count[counter][index];
            counter++;
            if(curr < est){
            est = curr;
            }
        }
        
        
    }
    return est;
}
