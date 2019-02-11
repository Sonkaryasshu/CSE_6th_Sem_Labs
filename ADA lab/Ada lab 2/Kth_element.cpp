#include <iostream>
using namespace std;


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


void Heap_sort_min(int arr[], int n,int k)
{
    int com=0;
	for (int i = n / 2 - 1; i >= 0; i--)
		heapify_min(arr, n, i);//min heap

	for (int i=n-1; i>=0; i--)
	{
		swap(arr[0], arr[i]);
		if(i==k-1){
            com++;
            cout<<k<<"th largest element is: "<<arr[i]<<endl;
		}
		else if(i==n-k){
		    com++;
            cout<<k<<"th smallest element is: "<<arr[i]<<endl;
		}
		if(com>=2)return;
		heapify_min(arr, i, 0);
	}
}


int main()
{
    int n,k;
	cout<<"Enter number of elements: ";
	cin>>n;
	int arr[n];
	cout<<"Enter "<<n<<" elements";
	for(int i=0;i<n;i++)
        cin>>arr[i];
	cout<<"Enter number k: ";
	cin>>k;
	Heap_sort_min(arr,n,k);
}
