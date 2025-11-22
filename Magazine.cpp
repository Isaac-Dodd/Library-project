#include "Magazine.h"

Magazine::Magazine() : Item()
{
	title = "1";
	edition = 1;
}
Magazine::Magazine(string n, string d, int i, string t, int e) : Item(n, d, i)
{
	edition = e;
	title = t;
}
Magazine::~Magazine() {
    cout << "destroying magazine";
}
void Magazine::setTitle(string t)
{
	title = t;
}
void Magazine::setEdition(int e)
{
	edition = e;
}
string Magazine::getTitle()const
{
	return(title);
}
int Magazine::getEdition()const
{
	return(edition);
}
void Magazine::getItemSpecifics() const
{
	cout << setw(12) << "Title: " << title << endl
		 << setw(12) << "Edition: " << edition << endl;
}
