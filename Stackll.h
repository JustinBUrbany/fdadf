#ifndef STACKLL_H
#define STACKLL_H
#include "List.h"
#include "Exception.h"

template<typename T>
class Stackll
{
public:
	Stackll();
	int Size();
	void Push(T & data);
	const T & Peek();
	const T & Pop();
	bool isEmpty();

private:
	List<T> m_stack;
	int m_size;

};

#endif

template<typename T>
inline Stackll<T>::Stackll() : m_size(-1)
{
}

template<typename T>
inline int Stackll<T>::Size()
{
	return m_size + 1;
}

template<typename T>
inline void Stackll<T>::Push(T & data)
{
	m_stack.Append(data);
	m_size++;
}

template<typename T>
inline const T & Stackll<T>::Peek()
{
	if (isEmpty())
		throw Exception("Nothing on the stack");
	return m_stack.Last();
}

template<typename T>
inline const T & Stackll<T>::Pop()
{
	if (isEmpty())
		throw Exception("Nothing is on stack");

	T temp = m_stack.Last();
	m_size--;
	m_stack.RemoveLast();

	return temp;
}

template<typename T>
inline bool Stackll<T>::isEmpty()
{
	return m_stack.isEmpty();
}
