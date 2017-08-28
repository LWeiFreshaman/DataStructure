#include "Stack.h"
#include <iostream>

using namespace std;

int main()
{
	Stack<int> s;
	for (int i = 0; i < 15; ++i)
		s.push(i);
	while (!s.empty())
	{	
		cout << s.top() << " ";
		s.pop();
	}
	cout << endl;
	
	return 0;
}
