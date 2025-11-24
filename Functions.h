#include "LibraryStorage.h"
using namespace std;

void addItemOption(LibraryStorage& storage, unordered_map<int, bool> &usedIds);
void addGeneralInfo(string &name,string & description, int &id, unordered_map<int, bool> usedIds);
Item* addBookInfo(LibraryStorage& storage, string name, string description, int id);
Item* addMovieInfo(LibraryStorage& storage, string name, string description, int id);
Item* addMagazineInfo(LibraryStorage& storage, string name, string description, int id);
void checkOutItemOption(LibraryStorage& storage);
void checkInItemOption(LibraryStorage& storage);
void swapItemsOption(LibraryStorage& storage);