#include <iostream>
#include "HashMap.h"
#include <cassert>
using namespace std;
int main()
{
	HashMap<string, int> hm;
	assert(hm.getNumberOfKeys() == 0);
	hm.add("exista", 10);
	assert(hm.getNumberOfKeys() == 1);
	hm.add("exista", 50);
	hm.add("poate", 30);
	assert(hm.getNumberOfKeys() == 2);
	assert(hm["exista"] == 10);
	assert(hm.getValuesOf("exista") == vector<int>({ 10,50 }));



	cout << hm;


}
