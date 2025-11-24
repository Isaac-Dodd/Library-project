#include "LibraryStorage.h"


LibraryStorage::LibraryStorage(int rows) 
{
    //each shelf defaults to filling with nullptrs
    storage.resize(rows);
}


void LibraryStorage::addItem(int rowNum, int colNum, Item* item)
{
    storage[rowNum][colNum].setCurrentItem(item);
}

void LibraryStorage::addShelf()
{
    storage.push_back(Shelf());
}

int LibraryStorage::occupiedSituation(int row, int col)
{
    // check if a checkedOut item is there
    for(auto& i : checkedOut)
    {
        if(row == i.second.second.first.first && col == i.second.second.first.second)
        {
            return 2;
        }
    }
    
    // check if an item is there
    if(storage[row][col].getCurrentItem() != nullptr) return 1;

    return 0;
}

// Compartment has a location, item doesn't
void LibraryStorage::checkOutItem(Compartment compartment, string name, string dueDate)
{
    // find index to store in checkedOut map
    vector<int> position = getIndex(compartment.getCurrentItem());

    // store item in checkedOut map
    checkedOut[compartment.getCurrentItem()->getId()] = {compartment.getCurrentItem(),{{position[0], position[1]}, {name, dueDate}}};


    storage[position[0]][position[1]] = nullptr;
}



void LibraryStorage::checkInItem(int id, string currentDate)
{
    if(checkedOut.find(id) == checkedOut.end()) 
        throw logic_error("ID not found; ");

    // create easier to use variable for id and dueDate
    string dueDate = checkedOut[id].second.second.second;

    // put item pointer back into original position
    storage[checkedOut[id].second.first.first][checkedOut[id].second.first.second].setCurrentItem(checkedOut[id].first);
    
    // delete item from checkedOut
    checkedOut.erase(id);

    // parse currentDate
    int m1 = stoi(currentDate.substr(0,2));
    int day1 = stoi(currentDate.substr(3,2));
    int y1 = stoi(currentDate.substr(6,4));

    // parse dueDate
    int m2 = stoi(dueDate.substr(0,2));
    int day2 = stoi(dueDate.substr(3,2));
    int y2 = stoi(dueDate.substr(6,4));

    // Compare year
    if (y1 < y2) 
    {
        cout << "You are just in time.\n";
    } 
    else if (y1 > y2) 
    {
        cout << "Your item is past its due date.\n";
    } 
    else // years equal
    { 
        // compare months
        if (m1 < m2) 
        {
            cout << "You are just in time.\n";
        } 
        else if (m1 > m2) {
            cout << "Your item is past its due date.\n";
        } 
        else // months equal
        { 
            // compare days
            if (day1 <= day2) 
            {
                cout << "You are just in time.\n";
            } 
            else {
                cout << "Your item is past its due date.\n";
            }
        }
    }
}

vector<int> LibraryStorage::getIndex(Compartment compartment)
{
    for(auto i = 0; i < storage.size(); ++i)
    {
        for(auto j = 0; j < SHELF_SIZE; ++j)
        {
            if(compartment.getCurrentItem() == storage[i][j].getCurrentItem())
            {
                return {i,j};
            }
        }
    }
    return {};
}



void LibraryStorage::printItemsInStorage()
{
    for(int i = 0; i < Shelf::getShelfCount(); ++i)
    {
        for(int j = 0; j < SHELF_SIZE; ++j)
        {
            if (storage[i][j].getCurrentItem() != nullptr)
            {
                cout << *storage[i][j].getCurrentItem() << endl << endl;
            }
        }
    }
}

void LibraryStorage::printCheckedOut()
{
    for(auto& i : checkedOut)
    {
        cout << *i.second.first << endl
             << setw(WIDTH) << "Name: " << i.second.second.second.first << endl
             << setw(WIDTH) << "Due Date: " << i.second.second.second.second << endl << endl;
    }
}

void LibraryStorage::swapItems(int row1, int column1, int row2, int column2)
{

    Compartment temp((storage[row1][column1]).getCurrentItem());
    
    storage[row1][column1] = storage[row2][column2];

    storage[row2][column2] = temp;
}

Shelf& LibraryStorage::operator[](int rows)
{
    return(storage[rows]);
}

Shelf LibraryStorage::operator[](int rows) const
{
    return(storage[rows]);
}
