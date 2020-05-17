#pragma once
#include "KeyHash.h"
#include <vector>
template<class K, class V, class F = KeyHash<K>>
class HashMap
{
protected:
	unsigned bucketCapacity;
	unsigned siz;
	unsigned nkeys;
	vector<vector<pair<K, vector<V>>>> v;
public:
	unsigned size();
	HashMap(unsigned max = 100, unsigned cap = 0) :siz(max), nkeys(0)
	{
		if (cap == 0)
			cap = max;
		bucketCapacity = cap;
		v.resize(cap);
	}
	HashMap(HashMap const& hm);
	HashMap operator=(const HashMap&);
	void add(K, V);
	bool search(K);
	void deleteKey(K);
	vector<V> getValuesOf(K);
	unsigned getNumberOfKeys();
	V operator[](K);
	friend ostream& operator<<(ostream& out, const HashMap<K, V, F>& hm)
	{
		out << "{\n";
		for (auto i : hm.v)
		{
			if (i.size())
			{
				for (auto z : i)
				{
					out << z.first << " : { " << z.second[0];
					for (int y = 1; y < z.second.size(); y++)
						out << " , " << z.second[y];
					out << " }\n";
				}
			}
		}
		out << '}';
		return out;
	}
};

template<class K, class V, class F>
inline unsigned HashMap<K, V, F>::size()
{
	return siz;
}

template<class K, class V, class F>
HashMap<K, V, F>::HashMap(HashMap const& hm)
{
	this->bucketCapacity = hm.bucketCapacity;
	this->siz = hm.siz;
	this->v = hm.v;
	this->nkeys = hm.nkeys;
}

template<class K, class V, class F>
inline HashMap<K, V, F> HashMap<K, V, F>::operator=(const HashMap& hm)
{
	if (&hm != this)
	{
		this->bucketCapacity = hm.bucketCapacity;
		this->siz = hm.siz;
		this->v = hm.v;
		this->nkeys = hm.nkeys;
	}
	return *this;
}

template<class K, class V, class F>
inline void HashMap<K, V, F>::add(K k, V val)
{
	unsigned i = F::hash(k) % bucketCapacity;
	for (auto& z : v[i])
		if (z.first == k)
		{
			z.second.push_back(val);
			return;
		}
	vector<V> f;
	f.push_back(val);
	v[i].push_back({ k,f });
	nkeys++;
}

template<class K, class V, class F>
inline bool HashMap<K, V, F>::search(K k)
{
	unsigned i = F::hash(k) % bucketCapacity;
	for (auto& z : v[i])
		if (z.first == k)
		{
			return true;
		}
	return false;
}

template<class K, class V, class F>
inline void HashMap<K, V, F>::deleteKey(K k)
{
	unsigned i = F::hash(k) % bucketCapacity;
	for (int j = 0; j < v[i].size(); j++)
		if (v[i][j].first == k)
		{
			v[i].erase(v[i].begin() + j);
			nkeys--;
			return;
		}
	throw "Nu exista cheie";
}

template<class K, class V, class F>
inline vector<V> HashMap<K, V, F>::getValuesOf(K k)
{
	unsigned i = F::hash(k) % bucketCapacity;
	for (auto& z : v[i])
		if (z.first == k)
		{
			return z.second;
		}
	throw "Nu exista cheie";
}

template<class K, class V, class F>
inline unsigned HashMap<K, V, F>::getNumberOfKeys()
{
	return nkeys;
}

template<class K, class V, class F>
inline V HashMap<K, V, F>::operator[](K k)
{
	unsigned i = F::hash(k) % bucketCapacity;
	for (auto& z : v[i])
		if (z.first == k)
		{
			return z.second[0];
		}
	throw "Nu exista cheie";
}
