#include "Shelf.h"

Shelf::Shelf()
{
	// already defaults to null from each compartment default constructing to null
}

Compartment& Shelf::operator[](int index)
{
	return (currentShelf.at(index));
}
