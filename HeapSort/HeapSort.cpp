#include<iostream>
using std::cin; using std::cout; using std::endl; using std::swap;

template<typename Type>
void HeapSortHelp(Type a[], int low, int high)
{
	for (int parent = low, child = 2 * parent + 1; child <= high; child = 2 * child + 1)
	{
		if (child < high && a[child] < a[child + 1]) ++child;
		if (a[parent] > a[child]) break;
		swap(a[parent], a[child]);
		parent = child;
	}
}

template<typename Type>
void HeapSort(Type a[], int n)
{
	for (int low = (n - 1) / 2; low >= 0; --low) HeapSortHelp<Type>(a, low, n - 1);
	for (int i = n - 1; i != 0; --i)
	{
		swap(a[0], a[i]);
		HeapSortHelp<Type>(a, 0, i - 1);
	}
}

int main()
{
	int a[10];
	cout << "Please enter 10 numbers as you want: ";
	for (auto &i : a) cin >> i;
	HeapSort<int>(a, 10);
	cout << "Low-to-High: ";
	for (auto &i : a) cout << i << "   "; cout << endl;
	return 0;
}