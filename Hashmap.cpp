#include <iostream>
#include "HashMap.h"
using namespace std;
int main()
{
	HashMap<string, int> hm;
	vector<int> v;
	v.push_back(1);
	cout << find(v.begin, v.end);
	cout << endl << hm;


}
