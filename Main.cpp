#include "LibraryStorage.h"
#include "Functions.h"
/* Error handle necessity
* No reusing ID's : METHOD : Register ID to an unordered map
*
* No swapping w/ empty slots
* No checking out a checked out item
* No checking out from empty slots - same technique as one above
* METHOD: Check for nullptr in the slot
* 
* No checking in a checked in item
* No checking in a non existing item
* No placing books where room DNE
* 
* No adding books to occupied compartments or checked out compartments
* 
* 
* No putting strings or chars into ints, like ID
*/



int main()
{
	
	int shelves;
	
	while (true)
	{
		try
		{
			cout << "How many shelves are in your library? ";
			cin >> shelves;
			if (cin.fail())
				throw runtime_error("Invalid input: Please enter an integer (Press Enter to continue)");
			else break;
		}

		catch (runtime_error& string)
		{
			cin.clear();
			cerr << "Error: " << string.what() << endl;
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
		}
	}

	LibraryStorage LibraryInventory(shelves);
	int userChoice = 0;
	bool continueLoop = true;
	unordered_map<int, bool> usedIds;


	while (continueLoop) 
	{

		try
		{
			cout << "Enter your choice: \n";
			cout << "1. Add an Item\n"
				 << "2. Checkout an Item\n"
				 << "3. Checkin an Item\n"
				 << "4. Print items in Storage\n"
				 << "5. Print Checked-Out Items\n"
				 << "6. Swap Items\n"
				 << "0. Exit Program\n";

			cin >> userChoice;
			
			if(cin.fail())
			{
				throw runtime_error("Invalid input: Please enter an integer (Press Enter to continue)");
			}
			cin.ignore();

			switch (userChoice)
			{
			case 1:
				addItemOption(LibraryInventory, usedIds);
				system("cls");
				cout << endl;
				break;
			case 2:
				checkOutItemOption(LibraryInventory);
				system("cls");
				cout << endl;
				break;
			case 3:
				checkInItemOption(LibraryInventory);
				system("cls");
				cout << endl;
				break;
			case 4:
				LibraryInventory.printItemsInStorage();
				cin.ignore();
				system("cls");
				cout << endl;
				break;
			case 5:
				LibraryInventory.printCheckedOut();
				cin.ignore();
				system("cls");
				cout << endl;
				break;
			case 6:

				swapItemsOption(LibraryInventory);
				system("cls");
				cout << endl;
				break;
			case 0:
				return 0;
				break;
			default:
				//add number of options
				throw runtime_error("Invalid Choice: Please enter a number between (Press Enter to continue)");
			}
		}

		catch (runtime_error& string) 
		{
			cin.clear();
			cerr << "Error: " << string.what() << endl;
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
 		}
		
		
		system("cls");
	}

	

	return 0;
}

