#include "Book.h"
#include "Magazine.h"
#include <vector>

int main()
{
	vector<Item*> library;
	library.push_back(new Book());
	library.push_back(new Magazine());
	cout << *library[0] << endl << *library[1];

	return 0;
}