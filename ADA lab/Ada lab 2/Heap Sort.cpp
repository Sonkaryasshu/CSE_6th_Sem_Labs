#include <iostream>
using namespace std;

//heapify functions
void heapify_max(int arr[], int n, int i)
{
	int largest = i;
	int l = 2*i + 1;
	int r = 2*i + 2;
	if (l < n && arr[l] > arr[largest])
		largest = l;
	if (r < n && arr[r] > arr[largest])
		largest = r;
	if (largest != i)
	{
		swap(arr[i], arr[largest]);
		heapify_max(arr, n, largest);
	}
}
void heapify_min(int arr[], int n, int i)
{
	int smallest = i;
	int l = 2*i + 1;
	int r = 2*i + 2;
	if (l < n && arr[l] < arr[smallest])
		smallest = l;
	if (r < n && arr[r] < arr[smallest])
		smallest = r;
	if (smallest != i)
	{
		swap(arr[i], arr[smallest]);
		heapify_min(arr, n, smallest);
	}
}

//Sorting Functions
void Heap_sort_max(int arr[], int n)
{
	for (int i = n / 2 - 1; i >= 0; i--)
		heapify_max(arr, n, i);//max heap

	for (int i=n-1; i>=0; i--)
	{
		swap(arr[0], arr[i]);
		heapify_max(arr, i, 0);
	}
}
void Heap_sort_min(int arr[], int n)
{
	for (int i = n / 2 - 1; i >= 0; i--)
		heapify_min(arr, n, i);//min heap

	for (int i=n-1; i>=0; i--)
	{
		swap(arr[0], arr[i]);
		heapify_min(arr, i, 0);
	}
}

void printArray(int arr[], int n)
{
	for (int i=0; i<n; ++i)
		cout << arr[i] << " ";
	cout << "\n";
}

int main()
{
    int n;
	cout<<"Enter number of elements:";
	cin>>n;
	int arr[n];
	cout<<"Enter "<<n<<" elements";
	for(int i=0;i<n;i++)
        cin>>arr[i];
	Heap_sort_min(arr, n);
    cout << "Sorted array (Min Heap) \n";
	printArray(arr, n);
	Heap_sort_max(arr, n);
    cout << "Sorted array (Max Heap) \n";
	printArray(arr, n);
}
