#ifndef REVERSELIST_H
#define REVERSELIST_H

#include <iostream>

template <typename T>
struct ListNode
{
	ListNode(T v) : value(v), next(nullptr) { }
	ListNode() { }

	ListNode<T> *next;
	T value;
};

template <typename T>
class MyList
{
public:
	MyList() : size(0), head(nullptr) { }
	MyList(const std::initializer_list<T> &ini);
	~MyList();
	ListNode<T>* push_back(const T& v);
	ListNode<T>* insert(const T& v, size_t pos);
	ListNode<T>* remove(const T& v);
	ListNode<T>* find(const T& v);
	ListNode<T>* getHead();
	ListNode<T>* findRing();

	friend std::ostream& operator << (std::ostream &os, const MyList<T>& l)
	{
		ListNode<T> *tmp = l.head;

		while (tmp)
		{
			os << tmp->value << " ";
			tmp = tmp->next;
		}

		return os;
	}

	friend void reverseList(MyList<T> &li)
	{
		if (li.size == 0)
			return;

		ListNode<T> *h = li.head;
		ListNode<T> *n = h->next;
		ListNode<T> *nn;
		li.head->next = nullptr;

		while (n)
		{
			nn = n->next;
			n->next = h;

			h = n;
			n = nn;
		}

		li.head = h;
	}

	ListNode<T>* reverseList_recursion_base(ListNode<T> *head) {
		if (head == nullptr || head->next == nullptr)
			return head;
		else
		{
			ListNode<T> *newNode = reverseList_recursion_base(head->next);

			head->next->next = head;
			head->next = nullptr;

			return newNode;
		}
	}

	void reverseList_recursion()
	{
		head = reverseList_recursion_base(head);
	}

private:
	ListNode<T> *head;
	size_t size;
	ListNode<T> *_hot;
};

template <typename T>
MyList<T>::MyList(const std::initializer_list<T> &ini) : size(0)
{
	for (auto i : ini)
	{
		push_back(i);
	}
}

template <typename T>
MyList<T>::~MyList()
{
	//查找有无成环，若有，拆掉
	if (auto ringPos = findRing())
	{
		//std::cout << _hot->value << std::endl;
		_hot->next = nullptr;
	}
	ListNode<T> *tmp = head, *tmpNext;

	while (tmp)
	{
		//std::cout << tmp->value << " ";
		tmpNext = tmp->next;
		delete(tmp);
		tmp = tmpNext;
	}
	std::cout << std::endl;

	head = nullptr;
	size = 0;
}

template <typename T>
ListNode<T>* MyList<T>::push_back(const T& v)
{
	if (size == 0)
	{
		ListNode<T> *node = new ListNode<T>(v);
		head = node;
		++size;
		return node;
	}

	ListNode<T> *tmp = head;
	while (tmp->next)
	{
		tmp = tmp->next;
	}
	ListNode<T> *node = new ListNode<T>(v);
	tmp->next = node;
	++size;

	return node;
}

template <typename T>
ListNode<T>* MyList<T>::insert(const T& v, size_t pos)
{
	if (pos + 2 > size)
		return nullptr;
	if (pos == 0)
	{
		ListNode<T> *node = new ListNode<T>(v);
		node->next = head;
		head = node;
		return node;
	}
	ListNode<T> *tmp = head;
	while (pos--)
	{
		tmp = tmp->next;
	}

	ListNode<T> *node = new ListNode<T>(v);
	node->next = tmp->next;
	tmp->next = node;
	++size;

	return node;
}

template<typename T>
ListNode<T>* MyList<T>::find(const T& v)
{
	ListNode<T> *tmp = head;
	while (tmp)
	{
		if (tmp->value == v)
			return tmp;
		_hot = tmp;
		tmp = tmp->next;
	}

	return nullptr;
}

template <typename T>
ListNode<T>* MyList<T>::remove(const T& v)
{
	ListNode<T> *tmp = find(v);

	if (tmp)
	{
		_hot->next = tmp->next;
		delete tmp;
		--size;
		return _hot;
	}

	return nullptr;
}

template <typename T>
ListNode<T>* MyList<T>::getHead()
{
	return head;
}

template <typename T>
ListNode<T>* MyList<T>::findRing()
{
	ListNode<T> *fast = head, *slow = head;

	do 
	{
		fast = fast->next->next;
		slow = slow->next;
	} while (fast && fast->next && fast != slow);
	//std::cout << fast->value << " " << slow->value << std::endl;
	if (fast == slow)
	{
		fast = head;
		while (fast != slow)
		{
			//std::cout << fast->value << " " << slow->value << std::endl;
			_hot = slow;
			fast = fast->next;
			slow = slow->next;
		}

		return fast;
	}
	return nullptr;
}


#endif
