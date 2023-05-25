#include <iostream>
#include <string>

using namespace std;

template<typename T>
class smartarray
{
private:
	int cap;
	int number_of_elements;
	T *arr;

public:
	smartarray(int size);
	~smartarray();
	const int size() ;
	void add(const T &obj);
	T& get(int index);
	T& operator[] (const int index);
};

template<typename T>
smartarray<T>::smartarray(int size )
{
	this->cap = size;
	this->number_of_elements = 0;
	this->arr = new T[this->cap];
}

template<typename T>
smartarray<T>::~smartarray()
{
	delete[] this->arr;
}

template<typename T>
const int smartarray<T>::size()
{
	return this->number_of_elements;
}

template<typename T>
void smartarray<T>::add(const T &obj)
{
	if (this->number_of_elements < this->cap)
		this->arr[this->number_of_elements++] = obj;
	else
		cout << "sorry but the array is full " << endl;
}

template<typename T>
T& smartarray<T>::get(int index)
{
	if (index < 0 || index >= this->number_of_elements)
		throw"invalid index";

	return this->arr[index];
}

template <typename T>
const int smartarray<T> :: size()
{
    return this -> number_of_elements;
}

int main()
{
	smartarray<int> test;
	smartarray<string> test2;

	for (size_t i = 0; i < 5; i++)
	{
		test.add(10);
		test2.add("HELLO!");
	}

	for (size_t i = 0; i < 5; i++)
	{
		cout << test.get(i) << endl;
		cout << test2.get(i) << endl;
	}
	return 0;
}
