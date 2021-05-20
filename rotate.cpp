
#include<bits/stdc++.h>
using namespace std;
void rotate(int arr[],int d, int n)
{
    int temp,i;
    
    while(d--)
    {
        temp=arr[0];
        for(i=0;i<n-1;i++)
        {
            arr[i]=arr[i+1];
        }
        arr[n-1]=temp;
    }
   
}

int main()
{
    int arr[]={1,2,3,4,5,6,7};
    int n=sizeof(arr) / sizeof(arr[0]);
     rotate(arr,2,n);
      for(int i=0;i<n;i++)
        cout<<arr[i]<<endl;
    return 0;
}