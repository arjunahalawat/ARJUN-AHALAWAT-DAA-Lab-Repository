#include <iostream>
#include <algorithm>
using namespace std;
int difference(int A[], int n, int key)
{
    sort(A,A+ n);
    int c=0;
    int l=0,r=1;

    while (r<n)
    {
        int diff=A[r]-A[l];

        if(diff==key)
        {
            c++;
            l++;
            r++;
        }
        else if(diff<key)
        {
            r++;
        }
        else
        {
            l++;
        }

        if(l==r)
        {
            r++;
        }
    }
    return c;
}
int main()
{
    int n, *A,t,key;
    cin>>t;
    while(t)
    {
        cin>>n;
        A = new int[n];
        for (int i = 0;i < n;i++)
        {
            cin >> *(A+ i);
        }
        cin>>key;
        int x=difference(A,n,key);
        cout<<x<<endl;
        delete[] A;
        t--;
    }
    return 0;
}
