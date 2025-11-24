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
	cout << setw(12) << "Title: " << title << endl
		<< setw(12) << "Author: " << author << endl
		<< setw(12) << "Copyright Date: " << crDate << endl;
}