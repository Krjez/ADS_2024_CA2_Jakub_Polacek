#pragma once
#include "BinaryTree.h"
#include "Entity.h"

template <class K, class V>
class TreeMap
{
	BinaryTree<Entity<K, V>> tree;

public:
	TreeMap();
	TreeMap(K key, V value);
	void add(K& key, V& value);
	V& get(K key);

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
	return tree.get(e).value;
}