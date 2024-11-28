#include "TreeMap.h"

int main()
{
	TreeMap<int, string> tree;
	int x = 12;
	int y = 5;
	string a = "aaa";
	string b = "bbb";
	tree.get(x);

	tree.add(x, a);
	tree.add(y, b);

	cout << "Size: " << tree.size() << endl;

	cout << tree.get(x) << endl;

	if (tree.containsKey(x))
	{
		cout << "X key found" << endl;
	}

	//tree.clear();

	BinaryTree<int> set = tree.keySet();

	set.printInOrder();


	return 0;
}