#pragma once
#ifndef "COMPARTMENT_H"
#define "COMPARTMENT_H"

#include "Item.h"
#include "Magazine.h"
#include "Book.h"
#include "Movie.h"

class Compartment
{
public:
Compartment();
Compartment(item*);

friend ostream& operator <<(ostream& out, const Item& item);

Compartment& operator[](int index);

private:

};

  
#endif
