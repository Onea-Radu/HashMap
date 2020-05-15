#pragma once
using namespace std;
template<typename K>
class KeyHash//am vrut un singleton si arata dubios, am vrut un utility si nu mergea mostenit, am ales chestia asta
{

	KeyHash<K>();
protected:
	static KeyHash<K>* currentInstance;
	virtual unsigned hashElement(const K&);//pentru a schimba metoda de hashing mainly(in cazul in care cineva vrea sa mosteneasca KeyHash),
									//nu puteam sa am un utilty care sa aiba virtual static deci aia e
public:
	static unsigned hash(const K&);
	static unsigned resetToBase();
};





template<class K>
KeyHash<K>* KeyHash<K>::currentInstance = 0;
template<typename K>
inline unsigned KeyHash<K>::hashElement(const K& el)
{
	return std::hash<K>()(el);
}
template<typename K>
unsigned KeyHash<K>::hash(const K& element)
{
	if (!currentInstance)
		currentInstance = new KeyHash<K>;
	return currentInstance->hashElement(element);
}






template<typename K>
inline unsigned KeyHash<K>::resetToBase()
{
	currentInstance = new KeyHash<K>;
}

template<typename K>
inline KeyHash<K>::KeyHash()
{
}
