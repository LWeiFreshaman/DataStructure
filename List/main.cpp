#include <iostream>
#include "MyList.h"

using namespace std;

int main()
{	
	MyList<int> l;
	for (int i = 0; i < 8; ++i)
	{
		l.push_back(i);
	}
	cout << l << endl;

	l.remove(5);

	cout << l << endl;

	l.insert(11, 0);
	l.insert(13, 7);
	l.insert(16, 9);

	cout << l << endl;
	
	MyList<int> li;
	for (int i = 0; i < 9; ++i)
	{
		li.push_back(i);
	}

	reverseList(li);

	cout << li << endl;

	li.reverseList_recursion();

	cout << li << endl;

	auto tmp = li.getHead();
	while (tmp->next)
	{
		tmp = tmp->next;
	}

	tmp->next = li.getHead()->next->next;

	//cout << li.getHead()->next->next->value << endl;
	if (auto ringPos = li.findRing())
		cout << ringPos->value << endl;

	MyList<int> l2{1, 2, 5, 8, 9, 11, 16};

	cout << l2 << endl;

	return 0;
}
