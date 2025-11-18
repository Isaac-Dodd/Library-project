#pragma once
#ifndef "SHELF_H"
#define "SHELF_H"

#include "Item.h"
#include "Magazine.h"
#include "Book.h"
#include "Movie.h"
  
class Shelf
{
public:
  Shelf()
  Item* & operator[](int index); // set up compartment data type
private:
  vector<item*>
};

#endif


