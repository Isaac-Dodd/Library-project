#include "Book.h"
#include "Magazine.h"
#include <vector>

int main()
{
	vector<Item*> library;

	try {
        library.push_back(new Book("Book1", "A good book", 101,
            "Title1", "Author1", "2019"));

        library.push_back(new Magazine());
    }
    catch (const exception& e) {
        cout << "Add error: " << e.what() << endl;
    }

    // Print all items
    try {
        cout << "\n--- Library Items ---\n";
        for (size_t i = 0; i < library.size(); i++) {
            if (library[i]) {
                cout << *library[i] << endl;
            }
            else {
                cout << "Empty spot at index " << i << endl;
            }
        }
    }
    catch (const exception& e) {
        cout << "Print error: " << e.what() << endl;
    }

    // Simulate checkout
    try {
        if (!library.empty() && library[0]) {
            cout << "\nChecking out item at index 0...\n";
            library[0]->checkOut("User", "12/10/2025");
        }
    }
    catch (const exception& e) {
        cout << "Checkout error: " << e.what() << endl;
    }

    // Simulate checkin
    try {
        if (!library.empty() && library[0]) {
            cout << "\nChecking in item with ID 101...\n";
            library[0]->checkIn();
        }
    }
    catch (const exception& e) {
        cout << "Checkin error: " << e.what() << endl;
    }

    // Swap two items
    try {
        if (library.size() > 1) {
            cout << "\nSwapping items 0 and 1...\n";
            swap(library[0], library[1]);
        }
    }
    catch (const exception& e) {
        cout << "Swap error: " << e.what() << endl;
    }

    // Print all items after swap
    try {
        cout << "\n--- Library Items After Swap ---\n";
        for (size_t i = 0; i < library.size(); i++) {
            if (library[i]) {
                cout << *library[i] << endl;
            }
            else {
                cout << "Empty spot at index " << i << endl;
            }
        }
    }
    catch (const exception& e) {
        cout << "Print error: " << e.what() << endl;
    }

    // Clean up memory
    for (auto item : library) {
        delete item;
    }
    library.clear();
	
	//library.push_back(new Book());
	//library.push_back(new Magazine());
	
	cout << *library[0] << endl << *library[1];

	return 0;
}