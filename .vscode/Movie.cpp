#include "Movie.h"

Movie::Movie()
{
	title = "0";
	director = "0";
	vector<string> emptyVec;
	cast = emptyVec;
}

Movie::Movie(string n, string d, int i, string t, string di, vector<string> c) : Item(n, d, i)
{
	title = t;
	director = di;
	cast = c;
}

void Movie::setTitle(string t)
{
	title = t;
}

void Movie::setDirector(string d)
{
	director = d;
}

void Movie::setCast(vector<string> c)
{
	cast = c;
}

string Movie::getTitle()
{
	return title;
}

string Movie::getDirector()
{
	return director;
}

vector<string> Movie::getCast()
{
	return cast;
}

void Movie::getItemSpecifics() const
{
	cout << title << endl
		<< director << endl;
	for (int i = 0; i < cast.size(); ++i)
	{
		cout << cast[i] << endl;
	}
}

Movie::~Movie()
{
	//cout << "destroyed";
}