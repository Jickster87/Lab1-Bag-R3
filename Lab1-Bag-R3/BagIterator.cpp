#include <exception>
#include "BagIterator.h"
#include "Bag.h"

using namespace std;


BagIterator::BagIterator(const Bag& c): bag(c)
{
    currentPosition = 0;
    freqCount = 1;
}

void BagIterator::first() {
    currentPosition = 0;
    freqCount = 1;
}


void BagIterator::next() {
  //TODO
}


bool BagIterator::valid() const {
	return currentPosition < bag.bagSizeUnique;
}



TElem BagIterator::getCurrent() const
{
    if (currentPosition == bag.bagSizeUnique) {
        throw exception();
    }
    return bag.uniqueArray[currentPosition];
}
