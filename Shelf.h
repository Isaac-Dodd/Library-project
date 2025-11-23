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

private:
	vector<Compartment> currentShelf;
};

