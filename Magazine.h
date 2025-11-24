#pragma once
#ifndef MAGAZINE_H_
#define MAGAZINE_H_
#include "Item.h"

class Magazine : public Item
{
public:
	Magazine();
	Magazine(string n, string d, int i, string t, int e);
	virtual ~Magazine();

	void setTitle(string t);
	void setEdition(int e);
	string getTitle()const;
	int    getEdition()const;
	void getItemSpecifics(/*ostream& os*/) const;

private:
	string title;
	int    edition;
};

#endif
