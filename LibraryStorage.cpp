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

void LibraryStorage::swapItems(Item* item1, Item* item2){
    // get positions of each item
    vector<int> position1 = item1.getIndex();
    vector<int> position2 = item2.getIndex();
    
    //Classic swap using temp variable
    Item* temp = storage[position1[0]][position1[1]];
    storage[position1[0]][position1[1]] = storage[position2[0]][position2[1]];
    storage[position2[0]][position2[1]] = temp;

    delete temp;
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
    return {};
}
