#include "Book.h"

Book::Book() : Item()
{
	title = "0";
	author = "0";
	crDate = "0";
}

Book::Book(string n, string d, int i, string t, string a, string cr) : Item(n, d, i)
{
	title = t;
	author = a;
	crDate = cr;
}

Book::~Book()
{
	cout << "destroying book";
}

void Book::setTitle(string t)
{
	title = t;
}

void Book::setAuthor(string a)
{
	author = a;
}

void Book::setCRDate(string d)
{
	crDate = d;
}

string Book::getTitle() const
{
	return title;
}

string Book::getAuthor() const
{
	return author;
}

string Book::getCRDate() const
{
	return crDate;
}

void Book::getItemSpecifics() const
{
	cout << left << setw(WIDTH) << "Title: " << title << endl
		<< setw(WIDTH) << "Author: " << author << endl
		<< setw(WIDTH) << "Copyright Date: " << crDate << endl;
}