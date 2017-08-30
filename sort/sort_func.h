#ifndef _SORT_FUNC_H_
#define _SORT_FUNC_H_

using std::swap;

//quick_sort
template <typename T>
T median3(T arr[], int left, int right)
{
	int center = (left + right) / 2;
	
	if (arr[center] < arr[left])
		swap(arr[center], arr[left]);
	if (arr[right] < arr[left])
		swap(arr[right], arr[left]);
	if (arr[right] < arr[center])
		swap(arr[right], arr[center]);
	
	swap(arr[center], arr[right - 1]);
	
	return arr[right - 1];
}

template <typename T>
void qsort(T arr[], int left, int right)
{
	if (right - left < 1)
		return;
	
	T pivot = median3(arr, left, right);
	
	int i = left;
	int j = right - 1; 
	
	while (i < j)
	{
		while (arr[++i] < pivot) { }
		while (pivot < arr[--j]) { }
	
		if (i < j)
			swap(arr[i], arr[j]);
	}
	
	swap(arr[i], arr[right - 1]);
	qsort(arr, left, i - 1);
	qsort(arr, i + 1, right);
}

template <typename T>
void quick_sort(T arr[], int n)
{
	qsort(arr, 0, n - 1);
}

#endif 
