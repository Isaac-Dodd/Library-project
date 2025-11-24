#include "Compartment.h"
Compartment::Compartment()
{
	currentItem = nullptr;
}

Compartment::Compartment(Item* addedItem)
{
	currentItem = addedItem;
}

void Compartment::setCurrentItem(Item* newItem)
{
	currentItem = newItem;
}

Item* Compartment::getCurrentItem()
{
	return(currentItem);
}

ostream& operator <<(ostream& out, Compartment item)
{
	out << *item.getCurrentItem();
	return(out);
}