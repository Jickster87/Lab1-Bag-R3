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
        capacityUnique *= 2;
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
    // search for the elem
    int elempos = -1;
    for (int i = 0; i < bagSizeUnique; i++) {
        if (uniqueArray[i] == elem) {
            elempos = i;
        }
    }
    
    // element not found then exit
    if (elempos == -1) {
        return false;
    }
    
    // element found, elempos != -1
    // Find the first occurrence of the element in posArray
    int posToRemove = -1;
    for (int j = 0; j < bagSizePos; j++) {
        if (posArray[j] == elempos) {
            posToRemove = j;
            break;
       }
    }
    // If no occurrence is found, return false
    if (posToRemove == -1) {
        return false;
    }
    
    // remove pos occurence
    posArray[posToRemove] = posArray[bagSizePos - 1];
    bagSizePos--;
        
    
    // if stillexists or not
    bool stillExists = false;
    for (int i = 0; i < bagSizePos; i++) {
        if (posArray[i] == elempos) {
            stillExists = true;
            break;
        }
    }
    
    // If no occurrences are left, remove the element from uniqueArray
    if (!stillExists) {
       // Swap the element in uniqueArray with the last element
        uniqueArray[elempos] = uniqueArray[bagSizeUnique - 1];
    
        bagSizeUnique--; // Decrease the size of uniqueArray

        // Update posArray to reflect the change in uniqueArray
        for (int j = 0; j < bagSizePos; j++) {
            if (posArray[j] == bagSizeUnique) {
                posArray[j] = elempos; // Update the index of the swapped element
           }
       }
   }


    
    return true;
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

