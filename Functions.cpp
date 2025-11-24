#include "Functions.h"
using namespace std;

void addItemOption(LibraryStorage& storage, unordered_map<int, bool>& usedIds)
{
	int userChoice = 0;
	bool itemIncomplete = true;

	string name;
	string description;
	int id;

	Item* userItem = nullptr;

	while (itemIncomplete)
	{
		try
		{
			cout << "What would you like to add?\n";
			cout << "Enter your choice: \n";
			cout << "1. Add a Book\n"
				<< "2. Add a Movie\n"
				<< "3. Add a Magazine\n";


			cin >> userChoice;

			if (cin.fail())
			{
				throw runtime_error("Invalid input: Please enter an integer (Press Enter to continue)");
			}
			else if (userChoice < 1 || userChoice > 3)
			{
				throw out_of_range("Invalid input : Please enter an integer in the range 1 to 3");
			}
            cin.ignore();

			switch (userChoice)
			{
			case 1:
				addGeneralInfo(name, description, id, usedIds);
				userItem = addBookInfo(storage, name, description, id);
				itemIncomplete = false;
				break;
			case 2:
				addGeneralInfo(name, description, id, usedIds);
				userItem = addMovieInfo(storage, name, description, id);
				itemIncomplete = false;
				break;
			case 3:
				addGeneralInfo(name, description, id, usedIds);
				userItem = addMagazineInfo(storage, name, description, id);
				itemIncomplete = false;
				break;
			}
		}
		catch (runtime_error& string)
		{
			cin.clear();
			cerr << "Error: " << string.what() << endl;
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
		}
		catch (out_of_range& string)
		{
			cout << string.what();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
		}
	}
	usedIds[id] = true;

	
	bool positionEmpty = false;

	
	do
	{
		bool validPosition = false;
		int row, col;

		do {
			cout << "Enter the position of the item (row, column): ";

			if (cin >> row >> col) // ints are read in
			{
				if (row >= 0 && row < Shelf::getShelfCount() &&
					col >= 0 && col < SHELF_SIZE) // check if positive and position in library
				{
					validPosition = true;
				}
				else
				{
					cout << "Enter an existing position. Library is "
						<< Shelf::getShelfCount() << " by " << SHELF_SIZE << endl;
				}
			}
			else
			{
				cout << "Invalid input. Please enter integers.\n";
			}
		} while (!validPosition);

		cin.ignore();
	
		try 
		{
		if (storage.occupiedSituation(row, col) != 0)
		{
			throw(out_of_range("Invalid input: space is already occupied"));
		}
		else if(validPosition)
		{
			storage.addItem(row, col, userItem);
			return;
		}

		}
		catch (out_of_range& string)
		{
			cout << string.what();
		}
	
	}while (!positionEmpty);
}



void addGeneralInfo(string& name, string& descprition, int& id, unordered_map<int, bool> usedIds)
{
    bool uniqueID = false;
    cout << "Enter the name: ";
    //cin.ignore();
    getline(cin, name);
    //cin.ignore();
    cout << "Please enter the description: ";
    getline(cin, descprition);

    while (uniqueID != true)
    {
        try
        {
            cout << "Enter a unique ID: ";
            cin >> id;
            if (cin.fail())
            {
                throw runtime_error("Invalid input: Please enter an integer (Press Enter to continue)");
            }
            else if (id < 0)
            {
                throw runtime_error("Invalid input: Please enter a positive integer (Press Enter to continue)");
            }
            else if (usedIds[id])
            {
                throw runtime_error("Invalid input: ID is already in use (Press Enter to continue)");
            }

            else uniqueID = true;

        }
        catch (runtime_error& string)
        {
            cin.clear();
            cerr << "Error: " << string.what() << endl;
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            //system("cls");
        }
    }
    cin.ignore();
}

Item* addMovieInfo(LibraryStorage& storage, string name, string description, int id)
{
	string title;
	string director;
	string actor;
	string userAnswer;
	bool insertingActors = true;

    
	cout << "Please enter the title: ";
	getline(cin, title);
    
    
	cout << "Please enter the director: ";
	getline(cin, director);
	
	vector<string> cast;
	
	
	cout << "Please enter an actor in the movie (type 'quit' to stop): ";
	
	
	while (true)
	{
		getline(cin, actor);
		if(actor == "quit") break;
		cast.push_back(actor);
        cout << "Please enter an actor in the movie (type 'quit' to stop): ";
	}

	return(new Movie(name, description, id, title, director, cast));

}

Item* addMagazineInfo(LibraryStorage& storage, string name, string description, int id)
{
    string title;
    int    edition;

    cout << "Enter the magazine's title: ";
    getline(cin, title);
    while (true)
    {
        try
        {
            
            cout << "Enter the magazine's edition: ";
            cin >> edition;
            cin.ignore();
            if (cin.fail())
                throw runtime_error("The edition must be an integer.");
            else if (edition < 0)
                throw runtime_error("Edition number cannot be negative.");
            else
                return new Magazine(name, description, id, title, edition);

        }
        catch (exception& string)
        {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cerr << "Error: " << string.what() << "\n";
        }
    }

    return new Magazine(name, description, id, title, edition);
}

Item* addBookInfo(LibraryStorage& storage, string name, string description, int id)
{
    string title;
    string author;
    string crDate;
    
    cout << "Enter the book's title: ";
    getline(cin, title);
    cout << "Enter its author: ";
    getline(cin, author);
    cout << "Enter its copyright date: ";
    getline(cin, crDate);

    return new Book(name, description, id, title, author, crDate);
}

void checkOutItemOption(LibraryStorage& storage)
{
    int row, col;
    bool validPosition = false;

    do {
        cout << "Enter the position of the item (row, column): ";

        if (cin >> row >> col) // ints are read in
        {
            cin.ignore();
            if (row >= 0 && row < Shelf::getShelfCount() &&
                col >= 0 && col < SHELF_SIZE) // check if positive and position in library
            {
                validPosition = true;
            }
            else
            {
                cout << "Enter an existing position. Library is "
                     << Shelf::getShelfCount() << " by " << SHELF_SIZE << endl;
            }
        }
        else
        {
            cout << "Invalid input. Please enter integers.\n";
        }
    } while (!validPosition);




    if (storage.occupiedSituation(row, col) == 1) // item is in position
    {
        string name, dueDate;
        cout << "Enter your name: ";
        getline(cin, name);

        cout << "Enter the date two weeks from today (mm/dd/yyyy): ";
        getline(cin, dueDate);

        storage.checkOutItem(storage[row][col], name, dueDate);
        cout << "Item checked out successfully.\n";
    }
    else // empty compartment
    {
        cout << "Current position is empty.\n";
    }
}

void checkInItemOption(LibraryStorage& storage)
{
    string currentDate;
    
    cout << "Enter the current date (mm/dd/yyyy): ";
    getline(cin, currentDate);

    int ID = 0;
    while (true)
    {
        try
        {
            cout << "Enter the ID of the book you are returning: ";
            cin >> ID;
            cin.ignore();
            if (cin.fail())
                throw runtime_error("Invalid input: Please enter an integer");
            else
            {
                storage.checkInItem(ID, currentDate);
                return;
            }
        }

        catch (runtime_error& string)
        {
            cin.clear();
            cerr << "Error: " << string.what() << endl;
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }

        catch (logic_error& string)
        {
            cin.clear();
            cerr << "Error: " << string.what() << "Please enter a valid ID (Press Enter to continue"
                << endl;
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cin.ignore(numeric_limits<streamsize>::max(), '\n');

        }
    }

}

void swapItemsOption(LibraryStorage& storage)
{
    int r1, c1, r2, c2;

    while (true)
    {
        try
        {
            cout << "Enter location of first item (row, col): \n";
            cin >> r1 >> c1;
            cin.ignore();
            if (cin.fail())
                throw runtime_error("Invalid input first shelf");
            else if (r1 < 0 || r1 >= Shelf::getShelfCount() ||
                c1 < 0 || c1 >= SHELF_SIZE)
                throw out_of_range("First item location out of bounds");
            else
                break;
        }
        catch (exception& string)
        {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cerr << "Error: " << string.what() << "\n";
        }
    }

    while (true)
    {
        try
        {
            cout << "Enter location of second item (row, col): \n";
            cin >> r2 >> c2;
            cin.ignore();
            if (cin.fail())
                throw runtime_error("Invalid input second shelf");
            else if (r2 < 0 || r2 >= Shelf::getShelfCount() ||
                c2 < 0 || c2 >= SHELF_SIZE)
                throw out_of_range("Second item location out of bounds");
            else
                break;
        }
        catch (exception& string)
        {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cerr << "Error: " << string.what() << "\n";
        }
    }

    try
    {
        if (storage.occupiedSituation(r1, c1) == 0)
            throw runtime_error("First item empty location");
        else if (storage.occupiedSituation(r2, c2) == 0)
            throw runtime_error("Second item empty location");
        else
        {
            storage.swapItems(r1, c1, r2, c2);
            cout << "\nItems are now swapped.\n";
        }
    }
    catch (exception& string)
    {
        cerr << "Error: " << string.what() << endl;
    }
}