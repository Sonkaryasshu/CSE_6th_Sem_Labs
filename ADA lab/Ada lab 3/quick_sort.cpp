#include <iostream>

using namespace std;

void swap(int* a, int* b)
{
    int t = *a;
    *a = *b;
    *b = t;
}

int part(int arr[],int l, int h){
    int i=l-1;
    int x=arr[h];
    for(int j=l;j<h;j++){
        if(arr[j]<=x){
            i++;
            swap(&arr[i],&arr[j]);
        }
    }
    i++;
    swap(&arr[i],&arr[h]);
    return i;
}

void quick_sort(int arr[],int l,int h){
    if(l<h){
        int index=part(arr,l,h);
        quick_sort(arr,l,index-1);
        quick_sort(arr,index+1,h);
    }
}

void print_array(int arr[],int n){
    for(int i=0;i<n;i++)
        cout<<arr[i]<<"\t";
    cout<<endl;
}

int main()
{
    int a[]={9,8,5,4,7,6,1,2,3,3,5};
    int n= sizeof(a)/sizeof(a[0]);
    quick_sort(a,0,n);
    print_array(a,n);

    return 0;
}
