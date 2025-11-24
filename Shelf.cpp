#include "Shelf.h"

int Shelf::shelfCount = 0;

Shelf::Shelf()
{
	// already defaults to null from each compartment default constructing to null
	shelfCount++;
}

Compartment& Shelf::operator[](int index)
{
	return (currentShelf.at(index));
}

const Compartment& Shelf::operator[](int index) const
{
	return currentShelf.at(index);     // const object ? read-only ref
}
int Shelf::getShelfCount()
{
	return shelfCount;
}

//ostream& operator <<(ostream& out, const Shelf shelf)
//{
//	for(int i = 0; i < SHELF_SIZE; ++i)
//	{
//		out << "Compartment " << i << ": " << shelf << endl;
//	}
//	return(out);
//}