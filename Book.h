#pragma once
#ifndef BOOK_H_
#define BOOK_H_
#include "Item.h"

class Book : public Item
{
public:
	Book();
	Book(string n, string d, int i, string t, string a, string cr);

	~Book();

	void setTitle(string t);
	void setAuthor(string a);
	void setCRDate(string d);

	string getTitle()const;
	string getAuthor()const;
	string getCRDate()const;
	void getItemSpecifics() const;

	//Shouldn't need this if we define getItemSpecifics and use that to output 
	//each of the derived class' specifics
	//friend ostream& operator <<(ostream& out, const Book& book);

private:
	string title;
	string author;
	string crDate;
};

#endif