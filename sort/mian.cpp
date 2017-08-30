#include <iostream>
#include "sort_func.h"

using namespace std;

int main()
{
	int a[] = {1, 2, 3, 6, 5, 4, 9, 7, 8, 4654, 185, 12165, 87, 154, 66, 98, 41, 45, 512, 487, 544, 866, 1564, 78, 42115, 711};
	quick_sort(a, sizeof(a)/sizeof(int));
	
	for (int i = 0; i < sizeof(a)/sizeof(int); ++i)
		cout << a[i] << " ";
	cout << endl;
	
	return 0;
}
