#include<iostream>
#define size 100
using namespace std;
void LinearSearch(int A[],int lb,int ub,int key)
{
    int i,c;
    for(i=lb;i<=ub;i++)
    {
        if(A[i]==key)
        {
            c=1;
            cout<<"Present\n";
        }
    }
    if(c!=1)
    {
        cout<<"Not Present\n";
    }
}
void ExpoSearch(int A[],int n,int key)
{
    if(A[0]==key)
    {
        cout<<"Present\n";
        return;
    }
    int i=1;
    while(i<n && A[i]<=key)
    {
        i=i*2;
    }
    LinearSearch(A,i/2,min(n-1,i),key);
}
int main()
{
    int n,A[size],i,j,t,key;
    cin>>t;
    j=1;
    while(j<=t)
    {
        cin>>n;
        for(i=0;i<n;i++)
        {
            cin>>A[i];
        }
        cin>>key;
        ExpoSearch(A,n,key);
        j=j+1;
    }
    return 1;
}
