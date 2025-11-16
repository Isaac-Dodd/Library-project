#include "Item.h"

Item::Item()
{
	name = "";
	description = "";
	id = 0;
}

Item::Item(string n, string d, int i)
{
	name = n; 
	description = d; 
	id = i; 
}

void Item::setName(string n) 
{ 
	name = n; 
}

void Item::setDescription(string d) 
{ 
	description = d; 
}

void Item::setId(int i)
{
	id = i;
}

string Item::getName() const
{
	return name;
}

string Item::getDescription() const
{
	return description;
}

int Item::getId() const
{
	return id;
}

Item::~Item()
{
	cerr << "Destroying item" << endl;
}

ostream& operator <<(ostream& out, const Item& item)
{
	out << setw(width) << "Name: " << item.name << endl
		<< setw(width) << "Description: " << item.description << endl
		<< setw(width) << "Id: " << item.id << endl;
	item.getItemSpecifics(/*out*/);
	return out;
}

