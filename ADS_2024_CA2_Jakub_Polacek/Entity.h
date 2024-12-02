#pragma once

template <class K, class V>
class Entity
{
	K key;
	V value;

public:
	Entity() {};
	Entity(K key, V value);
	V& getValue();
	K getKey();
	void setValue(V value);
	void setKey(K key);
	bool operator<(Entity& other);
	bool operator>(Entity& other);
	bool operator==(Entity& other);

	friend ostream& operator<<(ostream& out, Entity& ent)
	{
		return out << "Key: " << ent.key << ", of value: " << ent.value << "\n";
	}
};


template <class K, class V>
Entity<K,V>::Entity(K key, V value)
{
	this->key = key;
	this->value = value;
}

template <class K, class V>
V& Entity<K, V>::getValue()
{
	return this->value;
}

template <class K, class V>
K Entity<K, V>::getKey()
{
	return this->key;
}

template <class K, class V>
void Entity<K, V>::setValue(V value)
{
	this->value = value;
}

template <class K, class V>
void Entity<K, V>::setKey(K key)
{
	this->key = key;
}

template <class K, class V>
bool Entity<K, V>::operator<(Entity& other)
{
	return key < other.key;
}

template <class K, class V>
bool Entity<K, V>::operator>(Entity& other)
{
	return key > other.key;
}

template <class K, class V>
bool Entity<K, V>::operator==(Entity& other)
{
	return key == other.key;
}