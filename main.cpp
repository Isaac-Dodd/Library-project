#include <iostream>
#include <unordered_map>
#include <vector>

#include "LibraryStorage.h"
#include "Book.h"
#include "Movie.h"
#include "Magazine.h"

using namespace std;

bool registerId(int id, unordered_map<int, bool>& usedIDs) {
    if (usedIDs[id]) {
        cout << "Error: ID already used.\n";
        return false;
    }
    usedIDs[id] = true;
    return true;
}

int main() {

    // 15 shelves
    LibraryStorage library(15);

    // Track used IDs in main
    unordered_map<int, bool> usedIDs;

    try {
        // Add one Book
        if (!registerId(101, usedIDs))
            throw runtime_error("Duplicate ID detected.");

        Book* b = new Book("BookItem", "Classic poem", 101,
                           "The Odyssey", "Homer", "1998");
        library.addItem(0, 0, b);

        // Add one Movie
        if (!registerId(202, usedIDs))
            throw runtime_error("Duplicate ID detected.");

        Movie* m = new Movie("MovieItem", "Thriller movie", 202,
                             "Inception", "Christopher Nolan",
                             vector<string>{"Leonardo DiCaprio"});
        library.addItem(0, 1, m);

        // Add one Magazine
        if (!registerId(303, usedIDs))
            throw runtime_error("Duplicate ID detected.");

        Magazine* mg = new Magazine("MagazineItem", "Tech issue", 303,
                                    42, "AI Revolution");
        library.addItem(1, 0, mg);

    }
    catch (const exception& e) {
        cout << "Exception during adding items: " << e.what() << endl;
    }

    // Print storage
    library.printStorage();


    // Error Handling
    try {
        // Checkout movie
        cout << "\nChecking out item at shelf 0 compartment 1...\n";
        library.checkOutItem(0, 1, "Lily", "12/10/2025");

        // Print checked-out items
        library.printCheckedOut();

        // Check the movie back in
        cout << "\nChecking item ID 202 back in...\n";
        library.checkInItem(202);

        // Swap two items
        cout << "\nSwapping item in (0,0) with item in (1,0)...\n";
        library.swapItems(0, 0, 1, 0);
    }
    catch (const exception& e) {
        cout << "Exception during operations: " << e.what() << endl;
    }

    // Final print
    library.printStorage();

    return 0;
}
