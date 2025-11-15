#include "Magazine.h"

Magazine::Magazine() : Item()
{
	title = "1";
	edition = 1;

}

void Magazine::getItemSpecifics() const
{
	cout << setw(12) << "Inherited"
		<< "Inherited";
}