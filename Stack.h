#ifndef STACK_H
#define STACK_H
#include "Array.h"



template<typename T>
class Stack
{
public:
	Stack();
	Stack(int size);
	Stack(Stack & copy);
	Stack & operator=(Stack & rhs);
	~Stack();
	void Push(T Data);
	T & Pop();
	T & Peek();
	int SizeofStack();
	bool isEmpty();
	bool isFull();

private:
	int m_size;
	int m_position;
	Array<T> m_array;
};





#endif

template<typename T>
inline Stack<T>::Stack() : m_size(13), m_position(-1)
{
	m_array.setLength(m_size);
}

template<typename T>
inline Stack<T>::Stack(int size) : m_size(size), m_position(-1)
{
	m_array.setLength(size);
}

template<typename T>
inline Stack<T>::Stack(Stack & copy)
{
	*this = copy;
	return *this;
}

template<typename T>
inline Stack<T> & Stack<T>::operator=(Stack & rhs)
{
	if (this != &rhs)
	{
		m_size = rhs.m_size;
		m_array = rhs.m_array;
		m_position = rhs.m_position;
	}
	return *this;
}

template<typename T>
inline Stack<T>::~Stack()
{

}

template<typename T>
inline void Stack<T>::Push(T Data)
{
	if ((m_position + 1) >= m_size)
		throw Exception("Overflow");
	m_array[m_position + 1] = Data;
	m_position++;
}

template<typename T>
inline T & Stack<T>::Pop()
{
	if (m_position < 0)
		throw Exception("Underflow");
	m_position--;
	return m_array[m_position + 1];
}

template<typename T>
inline T & Stack<T>::Peek()
{
	if (m_position < 0)
		throw Exception("Nothing on Stack");
	return m_array[m_position];
}

template<typename T>
inline int Stack<T>::SizeofStack()
{
	return m_position + 1;
}

template<typename T>
inline bool Stack<T>::isEmpty()
{
	bool empty = false;
	if (m_position == -1)
	{
		empty = true;
	}
	return empty;
}

template<typename T>
inline bool Stack<T>::isFull()
{
	bool full = false;
	if (m_size == m_position + 1)
	{
		full = true;
	}
	return full;
}

