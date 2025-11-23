#pragma once

#include "Item.h"
#include "Book.h"
#include "Movie.h"
#include "Magazine.h"

class Compartment
{
public:
	Compartment();
	Compartment(Item*);
	void setCurrentItem(Item*);
	Item* getCurrentItem();

	friend ostream& operator <<(ostream& out, const Item& item);


private:
	Item* currentItem;
};

