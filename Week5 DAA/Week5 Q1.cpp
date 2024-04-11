#include <bits/stdc++.h>
using namespace std;

void frequency(char arr[], int n)
{
    int maxcount=1,flag=0;
    char ans;
    for (int i = 0; i < n; i++)
    {
        int count = 0;
        for (int j = 0; j < n; j++)
        {
            if (arr[i] == arr[j])
            {
                count++;
            }
        }
        if (count > maxcount)
        {
            maxcount = count;
            ans=arr[i];
            flag=1;
        }
    }
    if(flag==1)
    {
        cout<<ans<<"-"<<maxcount<<"\n";
    }
    else
    {
        cout<<"No Duplicates Exists\n";
    }
}
int main()
{
    int n,t;
    cin>>t;
    while(t>0)
    {
        cin>>n;
        char A[n];
        for(int i=0;i<n;i++)
        {
            cin>>A[i];
        }
        frequency(A,n);
        t--;
    }
    return 0;
}
