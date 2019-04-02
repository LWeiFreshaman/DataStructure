#include <iostream>
#include "reverseList.h"

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
	for (int i = 0; i < 0; ++i)
	{
		li.push_back(i);
	}

	reverseList(li);

	cout << li << endl;

	return 0;
}
