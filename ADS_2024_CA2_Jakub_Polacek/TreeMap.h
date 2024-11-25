#pragma once
#include "BinaryTree.h"
#include "Entity.h"

template <class K, class V>
class TreeMap
{
	BinaryTree<Entity<K, V>> tree;

public:
	TreeMap();
	void add(K& key, V& value);
	V& get(K key);
	void clear();
	bool containsKey(K key);
	BinaryTree<K> keySet();

	int size();

};

template <class K, class V>
TreeMap<K, V>::TreeMap()
{
	tree.root = nullptr;
}

template <class K, class V>
void TreeMap<K, V>::add(K& key, V& value)
{
	Entity<K, V> e(key, value);
	tree.add(e);
}

template <class K, class V>
V& TreeMap<K, V>::get(K key)
{
	Entity<K, V> e(key, V());
	try
	{
		//split into 2 lines to ensure that get method is getting entity, so that value is always there
		Entity<K, V> ent = tree.get(e);
		return ent.getValue();
	}
	catch (logic_error e)
	{
		//cout << e.what();
		V v;
		return v;
	}
}

template <class K, class V>
void TreeMap<K, V>::clear()
{
	tree.clear();
}

template <class K, class V>
bool TreeMap<K, V>::containsKey(K key)
{
	Entity<K, V> e(key, V());
	try
	{
		tree.get(e).getValue();
		return true;
	}
	catch (logic_error e)
	{
		return false;
	}
}

template <class K, class V>
int TreeMap<K, V>::size()
{
	return tree.count();

}