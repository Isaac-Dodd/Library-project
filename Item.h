#ifndef ITEM_H_
#define ITEM_H_
#include <string>
#include <iostream>
#include <iomanip>

using namespace std;
const int WIDTH = 12;
class Item {
public:
	Item();
	Item(string n, string d, int i);
	virtual ~Item();

	void setName(string n);
	void setDescription(string d);
	void setId(int i);

	string getName()const;
	string getDescription()const;
	int    getId()const;
	virtual void getItemSpecifics(/*ostream& os*/) const = 0;

	friend ostream& operator <<(ostream& out, const Item& item);

protected:
	string name;
	string description;
	int    id;
};


#endif