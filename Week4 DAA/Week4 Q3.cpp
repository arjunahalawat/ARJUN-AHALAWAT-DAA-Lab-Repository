#include<iostream>
using namespace std;
int main()
{
    int n,t;
    cin>>t;
    while(t)
    {
        cin >> n;
        int *A = new int[n];
        for (int i = 0; i < n; i++)
        {
            cin>>A[i];
        }
        for (int i = 0; i < n; i++)
        {
            cout<<A[i]<< " ";
        }
        cout<<endl;
        t--;
    }
}
