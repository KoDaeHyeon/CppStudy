#include <iostream>
#include "1022Store.h"
#include "1022Guest.h"

using namespace std;

int main()
{
	Store* store = new Store("ä��", "�峭��", "����","����", 3);

	store->PrintInfo();

	Guest* guest = new Guest("KK", 20000);
	guest->PerchaseObject(store, "ä��", 1000);
	guest->PerchaseObject(store, "�峭��", 5000);
	guest->PerchaseObject(store, "����", 25000);
	guest->PerchaseObject(store, "4B", 10000);

}