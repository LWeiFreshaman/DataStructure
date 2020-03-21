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

template <typename Comparable>
void bubble_sort(vector<Comparable>& vec)
{
    int flag = 0;
    for (int i = vec.size() - 1; i >0; --i)
    {
        flag = 0;
        for (int j = 0; j < i; ++j)
        {
            if (vec[j] > vec[j + 1])
            {
                swap(vec[j], vec[j + 1]);
                flag = 1;
            }
        }

        if (!flag)
            break;
    }
}

template <typename Comparable>
void insertion_sort(vector<Comparable>& vec)
{
    for (int i = 1; i < vec.size(); ++i)
    {
        int tmp = vec[i];
        int j;
        for (j = i; j > 0 && tmp < vec[j - 1]; --j)
        {
            vec[j] = vec[j - 1];
        }
        vec[j] = tmp;
    }
}

template <typename Comparable>
void shell_sort(vector<Comparable>& vec)
{
    for (int i = vec.size() / 2; i > 0; i /= 2)
    {
        for (int j = i; j < vec.size(); ++j)
        {
            int tmp = vec[j];
            int k;
            for (k = j; k > 0 && tmp < vec[k - i]; k -= i)
                vec[k] = vec[k - i];
            vec[k] = tmp;
        }
    }
}

#endif 
