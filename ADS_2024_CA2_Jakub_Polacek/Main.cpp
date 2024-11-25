#include "TreeMap.h"

int main()
{
	TreeMap<int, string> tree;
	int x = 12;
	string a = "dd";
	tree.get(x);

	tree.add(x, a);

	cout << tree.get(x) << endl;

	if (tree.containsKey(x))
	{
		cout << "X key found" << endl;
	}

	tree.clear();


	return 0;
}