#ifndef _STACK_H__
#define _STACK_H__

const int MaxSize = 100;

template <typename T>
class Stack
{
public:
	Stack();
	~Stack() {};
	bool empty();
	bool isFull();
	bool push(T data);
	bool pop();
	T top();
private:
	int m_top;
	T elem[MaxSize];
};

template <typename T>
Stack<T>::Stack() : m_top(-1)
{
	
}

template <typename T>
bool Stack<T>::empty()
{
	return m_top == -1;
}

template <typename T>
bool Stack<T>::isFull()
{
	return !(m_top < MaxSize - 1);
}

template <typename T>
bool Stack<T>::push(T data)
{
	if (isFull())
		return false;
	elem[++m_top] = data;
	return true;
}

template <typename T>
bool Stack<T>::pop()
{
	if (empty())
		return false;
	elem[m_top--] = 0;
	return true;
}

template <typename T>
T Stack<T>::top()
{
	return elem[m_top];
}

#endif
