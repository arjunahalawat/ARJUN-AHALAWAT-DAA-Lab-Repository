#include<iostream>
#define size 100
using namespace std;
int main()
{
    int A[size],i,j,t,n,key,c1,c2;
    //Enter the test cases
    cin>>t;
    while(t)
    {
        //Enter the number of elements of array
        cin>>n;
        //Enter the elements in the array
        for(i=0;i<n;i++)
        {
            cin>>A[i];
        }
        c1=0;
        c2=0;
        for(i=1;i<n;i++)
        {
            key=A[i];
            j=i-1;
            while(j>=0 && A[j]>key)
            {
                c1++;
                A[j+1]=A[j];
                j--;
                c2++;
            }
            A[j+1]=key;
            c2++;
        }
        //The Sorted array is
        for(i=0;i<n;i++)
        {
            cout<<A[i]<<" ";
        }
        cout<<"\nComparisons="<<c1;
        cout<<"\nShifts="<<c2;
        t--;
    }
}
