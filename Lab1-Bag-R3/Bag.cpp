#include "Bag.h"
#include "BagIterator.h"
#include <exception>
#include <iostream>
using namespace std;


Bag::Bag() {
    capacityUnique = capacityPos = 32;
    bagSizeUnique = 0;
    bagSizePos = 0;
    uniqueArray = new TElem[capacityUnique];
    posArray = new TElem[capacityPos];
}


void Bag::add(TElem elem) {
	//resize posArray
    if (bagSizePos == capacityPos) {
        capacityPos *= 2;
           TElem* tempArray = new TElem[capacityPos];
           int i = 0;
           while (i < bagSizePos) {
               tempArray[i] = posArray[i];
               i++;
           }
           delete [] posArray;
            posArray = tempArray;
       }
    //resize uniqueArray
    if (bagSizeUnique == capacityUnique) {
        //capacityTotal *= 2;
           TElem* tempoArray = new TElem[capacityUnique];
           int i = 0;
           while (i < bagSizeUnique) {
               tempoArray[i] = uniqueArray[i];
               i++;
           }
           delete [] uniqueArray;
        uniqueArray = tempoArray;
       }
    
    //add to the unique array if not found
    bool found = false;
    int i;
    for (i = 0; i < bagSizeUnique; i++) {
        if (uniqueArray[i] == elem) {
            found = true;
            break;
        }
    }
    if (found) {
        posArray[bagSizePos] = i;
        bagSizePos++;
    } else {
        uniqueArray[bagSizeUnique] = elem;
        posArray[bagSizePos] = i;
        bagSizePos++;
        bagSizeUnique++;
    }
}


bool Bag::remove(TElem elem) {
	/* bad version1 xD
    //find elem
    int elemPos = -1;
    for (int i = 0; i < bagSizeUnique; i++) {
        //if found elempos = found[i]
        if (uniqueArray[i] == elem) {
            elemPos = i;
            break;
        }
    }

    //count occurrences
    int counter = 0;
    for (int j = 0; j < bagSizePos; j++) {
        if (posArray[j] == elemPos) {
            counter++;
        }
    }
    if (counter > 1) {
        for (int k = 0; k < bagSizePos; k++) {
            if (posArray[k] == elemPos) {
                posArray[k] = posArray[bagSizePos];
                bagSizePos--;
            }
        }
        return true;
    }
    
    if (counter == 1)
    {
        for (int l = 0; l < bagSizePos; l++) 
        {
            if (posArray[l] == elemPos) 
            {
                posArray[l] = posArray[bagSizePos];
                bagSizePos--;
            }
        }
        for (int m = 0; m < bagSizePos; m++)
        {
            if (uniqueArray[m] == elem)
            {
                uniqueArray[m] = uniqueArray[bagSizeUnique];
                bagSizeUnique--;
            }
        }
    }
  
    
    return false;
    end of bad version 1 */
    
    // bad version remove 2 xDDD
    int elempos = -1;
    int counter = 0;
    int i;
    int j = 0;
    for (i = 0; i < bagSizeUnique; i++) {
        if (uniqueArray[i] == elem) {
            elempos = i;
            //count occurences in posArray
            for (j = 0; j < bagSizePos; j++) {
                if (posArray[j] == elempos) {
                    counter++;
                }
            }
            return counter;
        }
    }
    if (elempos == -1) {
        return false;
    }
    
    if (counter > 1) {
        posArray[j] = posArray[bagSizePos];
        bagSizePos--;
        uniqueArray[i] = uniqueArray[bagSizeUnique];
        bagSizeUnique--;
        return true;
    } else {posArray[j] = posArray[bagSizePos];
        bagSizePos--;
        return true;
        }
}


bool Bag::search(TElem elem) const {
	
    for (int i=0; i<bagSizeUnique; i++) {
        if (uniqueArray[i] == elem) {
            return true;
        }
    }
    
	return false;
}

int Bag::nrOccurrences(TElem elem) const {
    int elemPos = -1;
    for (int i = 0; i < bagSizeUnique; i++) {
        if (uniqueArray[i] == elem) {
            elemPos = i;
            break;
        }
    }

    if (elemPos == -1) {
        return 0; // Element not found
    }

    int counter = 0;
    for (int j = 0; j < bagSizePos; j++) {
        if (posArray[j] == elemPos) {
            counter++;
        }
    }

    return counter;
}


int Bag::size() const {
	//TODO - Implementation
	return bagSizePos;
}


bool Bag::isEmpty() const {
	//TODO - Implementation
	return bagSizePos==0;
}

BagIterator Bag::iterator() const {
	return BagIterator(*this);
}


Bag::~Bag() {
	//TODO - Implementation
    delete[] uniqueArray;
    delete[] posArray;
}

