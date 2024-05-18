#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cout<<"Enter the number of elements"<<endl;
    cin>>n;
    cout<<"Enter the elements"<<endl;
    vector<int>arr(n);
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    sort(arr.begin(),arr.end());
    map<int,int>mp;
    int f=0;
    for(int i=0;i<n;i++)
    {
        mp[arr[i]]++;
        if(mp[arr[i]]>n/2)
        {
            cout<<"yes"<<endl;
            f=1;
             break;
        }
    }
    if(f==0)
    cout<<"no "<<endl;
    int med;
    if(n%2!=0)
    {
        med=arr[((n+1)/2)-1];
    }
    else
    {
        med=(arr[(n/2)-1]+arr[(n/2+1)-1])/2;
    }
    cout<<"median of the elements is : "<<med<<endl;
    return 0;
}
