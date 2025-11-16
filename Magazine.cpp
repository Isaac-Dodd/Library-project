#include "Magazine.h"

Magazine::Magazine() : Item()
{
	title = "1";
	edition = 1;
}
Magazine::Magazine(string n, string d, int i, string t, int e) : Item(n, d, i)
{
	edition = e;
	author = a;
}
void setTitle(string t)
{
	title = t;
}
void setEdition(int e)
{
	edition = e;
}
string getTitle()const
{
	return(title);
}
int    getEdition()const
{
	return(edition);
}
void Magazine::getItemSpecifics() const
{
	cout << setw(12) << "Title: " << title << endl
		 << setw(12) << "Edition: " << edition << endl;
}
