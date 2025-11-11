#include "LibraryStorage.h"


LibraryStorage::LibraryStorage(int rows){
    //vector<int>(columns) creates a shelf with "column" # of compartments
    storage.resize(rows);
}

vector<Item*>& LibraryStorage::operator[](int row){
    //Access specific shelf
    return storage[row];
}

void LibraryStorage::addItem(int rowNum, Item* item){
    
}

void LibraryStorage::swapItems(int row1, int column1, int row2, int column2){
    
    if (storage[row1][column1] == nullptr || storage[row2][column2] == nullptr){
        
    }
    //Classic swap using temp variable
    Item* temp = storage[row1][column1];
    storage[row1][column1] = storage[row2][column2];
    storage[row2][column2] = temp;
}
