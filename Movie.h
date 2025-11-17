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

	//friend ostream& operator <<(ostream& out, Movie& movie)
	//{
	//	out << movie.item
	//		<< setw(12) << "Title: " << movie.title << endl
	//		<< setw(12) << "Director: " << movie.director << endl
	//		<< setw(12) << "Main Actors: ";
	//	for (auto& i : movie.cast)
	//	{
	//		out << i << ", ";
	//	}
	//	out << endl;

	//	return out;
	//}

private:
	string title;
	string director;
	vector<string> cast;
};

#endif
