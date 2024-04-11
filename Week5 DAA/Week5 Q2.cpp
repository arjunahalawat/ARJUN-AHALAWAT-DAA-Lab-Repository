#include<bits/stdc++.h>
using namespace std;
vector<int>Sum(vector<int>A,int n,int key)
{
    vector<int>T;

    sort(A.begin(),A.end());
    int i=0,j=n-1;
    while(i<j)
    {
        if(A[i]+A[j]==key)
        {
            T.push_back(A[i]);
            T.push_back(A[j]);
            return T;
        }
        else if(A[i]+A[j]<key)
        {
            i++;
        }
        else
        {
            j--;
        }
    }
    return T;
}

int main()
{
    int t,n,i,key;
    cin>>t;
    while(t>0)
    {
        cin >> n;
        vector<int>A(n);
        for ( i = 0; i < n; i++)
        {
            cin>>A[i];
        }
        cin>>key;
        vector<int>ans = Sum(A,n,key);
        if(ans.empty())
        {
            cout<<"No Such Elements Exists"<<endl;
        }
        else
        {
            cout<<ans[0]<<" "<<ans[1]<<endl;
        }
        t--;
    }
    return 0;
}
