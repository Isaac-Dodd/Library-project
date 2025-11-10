#ifndef LIBRARYSTORAGE_H
#define LIBRARYSTORAGE_H

#include <iostream>
#include <vector>
#include "Item.h"
using namespace std;


class LibraryStorage{
    private:
    //2D vector that stores the shelf and compartments
    //Outer vector = rows
    //Inner vector = columns
        vector<vector<Item*>> storage;
    public:
    //Constructor that initializes given # of rows and columns
        LibraryStorage(int rows);
    //Overloaded [] operator that allows access to a certain shelf
    //returns by reference in order to modify the elements of storage directly
        vector<Item*>& operator[](int index);
        void printStorage() const;
    //Adds an item, presumably in an empty shelf, using throw/catch exceptions for overflow/outofrange errors
        void addItem(int rowNum, Item* item);
    //Swaps any two items within the storage given their locations
        void swapItems();

};

#endif
