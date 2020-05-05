#include "BloomFilter.h"
#include "HashFunctions.h"

/**
 * Implement insert() correctly
 */
void BloomFilter::insert(const string & s) {
    /* YOUR CODE HERE */
    for(auto const & iter : hash_functions){
        bits[iter(s) % M] = true;
        //int index = iter(s) % M;
        //bits[index] = true 
    }
}

/**
 * Implement find() correctly
 */
bool BloomFilter::find(const string & s) {
    /* YOUR CODE HERE */
    for(auto const& iter : hash_functions){
        if(bits[iter(s) % M] == false){
            return false;
        }

    }
    return true;   
}
