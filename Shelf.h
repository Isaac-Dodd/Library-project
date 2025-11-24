#pragma once
#include "Compartment.h"

const int SHELF_SIZE = 15;

class Shelf
{
public:
	Shelf();
	//Shelf(Item*);

	vector<Compartment> shelf;

	Compartment& operator[](int index);

	const Compartment& operator[](int index) const;
	//friend ostream& operator <<(ostream&, const Shelf);

	static int getShelfCount();


private:
	vector<Compartment> currentShelf = vector<Compartment>(15);
	static int shelfCount;
};