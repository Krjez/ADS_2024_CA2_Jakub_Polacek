#include "TreeMap.h"

int main()
{
	TreeMap<int, string> tree;
	int x = 12;
	int y = 5;
	int z = 10;
	string a = "aaa";
	string b = "bbb";
	string c = "ccc";

	tree.put(x, a);
	tree.put(y, b);
	tree.put(z, c);

	cout << "Size: " << tree.size() << endl;

	cout << tree.get(x) << endl;

	BinaryTree<int> set = tree.keySet();
	set.printInOrder();

	tree.removeKey(x);

	set = tree.keySet();
	set.printInOrder();

	return 0;
}