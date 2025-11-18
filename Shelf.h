#pragma once
#ifndef "SHELF_H"
#define "SHELF_H"

#include "Compartment.h"
  
class Shelf
{
public:
  Shelf()
  Shelf(int, item*);
  Compartment & operator[](int index); // set up compartment data type
private:
  Compartment  
};

#endif
