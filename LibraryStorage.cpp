#include "LibraryStorage.h"


LibraryStorage::LibraryStorage(int rows){
    //fill each shelf with nullptrs
    storage.resize(rows, vector<Item*>(15));
}

vector<Item*>& LibraryStorage::operator[](int row){
    //Access specific shelf
    return storage[row];
}

void LibraryStorage::addItem(int rowNum, int colNum, Item item){ 
    storage[rowNum][colNum] = new Item[item];
}

void LibraryStorage::swapItems(int row1, int column1, int row2, int column2){
    
    if (storage[row1][column1] == nullptr || storage[row2][column2] == nullptr){
        
    }
    //Classic swap using temp variable
    Item* temp = storage[row1][column1];
    storage[row1][column1] = storage[row2][column2];
    storage[row2][column2] = temp;
}

friend ostream& operator << (ostream& out, const LibraryStorage& library){
    
}

void checkOutItem(Item* item, string name, string dueDate)
{
    // find index to store in checkedOut map
    vector<int> position = getIndex(item);

    // store item in checkedOut map
    checkedOut[item->getId()] = {item,{{position[0], position[1]}, {name, dueDate}}};

    // remove item in storage?
    storage[position[0]][position[1]] = nullptr;
}
void LibraryStorage::checkInItem(Item* item)
{
    // create easier to use variable for id
    int id = item->getId();

    // put item pointer back into original position
    storage[checkedOut[id].second.first.first][checkedOut[id].second.first.second] = item;

    // delete item from checkedOut
    checkedOut.erase(id);
}
vector<int> LibraryStorage::getIndex(Item* item)
{
    for(int i = 0; i < storage.size(); ++i)
    {
        for(int j = 0; j < storage[0].size(); ++j)
        {
            if(item == &storage[i][j])
            {
                return {i,j};
            }
        }
    }
}
