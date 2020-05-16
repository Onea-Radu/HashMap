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
	assert(hm.search("poate"));
	assert(!hm.search("pot"));
	hm.deleteKey("poate");
	assert(hm.getNumberOfKeys() == 1);
	assert(!hm.search("poate"));

	try {

		hm.getValuesOf("poate");
		assert(false);
	}
	catch (...) {


	}


	try {

		hm["poate"];
		assert(false);
	}
	catch (...) {


	}

	try {

		hm.deleteKey("poate");
		assert(false);
	}
	catch (...) {


	}



	cout << hm;


}
