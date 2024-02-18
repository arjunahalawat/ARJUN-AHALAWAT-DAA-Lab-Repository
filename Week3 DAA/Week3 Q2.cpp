#include<iostream>
#define size 100
using namespace std;
int main()
{
    int A[size],i,j,t,n,min,c1,c2;
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
        for(i=0;i<n-1;i++)
        {
            min=i;
            for(j=i+1;j<n;j++)
            {
                c1++;
                if(A[j]<A[min])
                {
                    min=j;
                }
            }
            if(A[min]!=i)
            {
                c2++;
                int temp=A[min];
                A[min]=A[i];
                A[i]=temp;
            }
        }
        //The Sorted array is
        for(i=0;i<n;i++)
        {
            cout<<A[i]<<" ";
        }
        cout<<"\nComparisons="<<c1;
        cout<<"\nSwaps="<<c2;
        t--;
    }
}

