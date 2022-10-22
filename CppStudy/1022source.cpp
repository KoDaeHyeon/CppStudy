#include <iostream>
#include "1022Store.h"
#include "1022Guest.h"

using namespace std;

int main()
{
	Store* store = new Store("채소", "장난감", "연필","음식", 3);

	store->PrintInfo();

	Guest* guest = new Guest("KK", 20000);
	guest->PerchaseObject(store, "채소", 1000);
	guest->PerchaseObject(store, "장난감", 5000);
	guest->PerchaseObject(store, "음식", 25000);
	guest->PerchaseObject(store, "4B", 10000);

}