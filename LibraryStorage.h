#ifndef LIBRARYSTORAGE_H
#define LIBRARYSTORAGE_H

#include <iostream>
#include <vector>
#include "Item.h"
#include "Magazine.h"
#include "Book.h"
#include "Movie.h"
using namespace std;


class LibraryStorage{
    private:
    //2D vector that stores the shelf and compartments
    //Outer vector = rows
    //Inner vector = columns
        vector<vector<Item*>> storage;

    // key = id of item    item pointer, pair of og position and name/due date
        unordered_map<int, pair<Item*,pair<pair<int,int>, pair<string,string>>>> checkedOut;

    public:
    //Constructor that initializes given # of rows and columns
        LibraryStorage(int rows);
    //Overloaded [] operator that allows access to a certain shelf
    //returns by reference in order to modify the elements of storage directly
        vector<Item*>& operator[](int index);
        friend ostream& operator << (ostream& out, const LibraryStorage& library);
    //Adds an item, presumably in an empty shelf, using throw/catch exceptions for overflow/outofrange errors
        void addItem(int rowNum, int colNum, Item item);
    //Swaps any two items within the storage given their locations
        void swapItems(Item* item1, Item* item2);
        void checkInItem(Item* item, string user, string dueDate);
        void checkOutItem(Item* item);
        vector<int> getIndex(Item* item);

};

#endif
