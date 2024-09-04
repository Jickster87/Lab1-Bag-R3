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
	//TODO - Implementation
	return false; 
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
    int index = -1;
    for (int i = 0; i < bagSizeUnique; i++) {
        if (uniqueArray[i] == elem) {
            index = i;
            break;
        }
    }

    if (index == -1) {
        return 0; // Element not found
    }

    int counter = 0;
    for (int j = 0; j < bagSizePos; j++) {
        if (posArray[j] == index) {
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

