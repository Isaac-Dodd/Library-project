#pragma once

#include "Shelf.h"
#include <unordered_map>
#include <algorithm>

class LibraryStorage
{
public:
    LibraryStorage(int);
    void addItem(int rowNum, int colNum, Item* item);
    void printItemsInStorage();
    void printCheckedOut();
    int occupiedSituation(int row, int col);

    void addShelf();

    vector<int> getIndex(Compartment compartment);
    void checkInItem(int id, string currentDate);
    void checkOutItem(Compartment compartment, string user, string dueDate);

    
    Shelf& operator[](int rows);
    Shelf operator[](int rows) const;

    void swapItems(int row1, int column1, int row2, int column2);


private:
    vector<Shelf> storage;
    
    // key = id of item    item pointer, pair of og position and name/due date
    unordered_map<int, pair<Item*,pair<pair<int,int>, pair<string,string>>>> checkedOut;
};