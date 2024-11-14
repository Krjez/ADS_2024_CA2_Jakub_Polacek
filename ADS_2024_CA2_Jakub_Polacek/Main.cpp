#include "TreeMap.h"

int main()
{
	TreeMap<int, string> tree;
	int x = 12;
	string a = "dd";
	tree.add(x, a);

	cout << tree.get(x) << endl;


	return 0;
}