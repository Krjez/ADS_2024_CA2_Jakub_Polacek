#pragma once

template <class K, class V>
struct Entity
{
	K key;
	V value;

public:
	Entity(){}

	Entity(K key, V value)
	{
		this->key = key;
		this->value = value;
	}
	
	bool operator<(Entity& other)
	{
		return key < other.key;
	}

	bool operator>(Entity& other)
	{
		return key > other.key;
	}

	bool operator==(Entity& other)
	{
		return key == other.key;
	}

	friend ostream& operator<<(ostream& out, Entity& ent)
	{
		return out << "Key: " << ent.key << ", of value: " << ent.value << "\n";
	}
};