#include <iostream>

using namespace std;

int **strassen(int **a, int **b, int n){
    int **ans=0;
    ans= new int*[n];
    for(int i=0;i<n;i++) ans[i]= new int[n];
    if(n==2){
        ans[0][0]=a[0][0]*b[0][0] + a[0][1]*b[1][0];
        ans[0][1]=a[0][0]*b[0][1] + a[0][1]*b[1][1];
        ans[1][0]=a[1][0]*b[0][0] + a[1][1]*b[1][0];
        ans[1][1]=a[1][0]*b[0][1] + a[1][1]*b[1][1];
        return ans;
    }
}

int main()
{
    int n=2;
    int **a=0;
    a= new int*[n];
    for(int i=0;i<n;i++) a[i]= new int[n];
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++){
            cout<<"a["<<i<<"]["<<j<<"]=";
            cin>>a[i][j];
        }
    int **b=0;
    b= new int*[n];
    for(int i=0;i<n;i++) b[i]= new int[n];
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++){
            cout<<"b["<<i<<"]["<<j<<"]=";
            cin>>b[i][j];
        }
    int **ans= strassen(a,b,n);
    for(int i=0;i<n;i++, cout<<endl)
        for(int j=0;j<n;j++) cout<<ans[i][j]<<"\t";
    return 0;
}
