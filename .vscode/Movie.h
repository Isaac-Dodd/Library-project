#pragma once
#ifndef MOVIE_H_
#define MOVIE_H_
#include "Item.h"
#include <vector>

class Movie : public Item
{
public:
	Movie();
	Movie(string n, string d, int i, string t, string di, vector<string> c);
	virtual ~Movie();

	void setTitle(string t);
	void setDirector(string d);
	void setCast(vector<string> c);

	string getTitle();
	string    getDirector();
	vector<string> getCast();
	void getItemSpecifics() const;

private:
	string title;
	string director;
	vector<string> cast;
};

#endif