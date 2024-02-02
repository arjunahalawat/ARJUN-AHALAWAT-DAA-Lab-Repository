#include<iostream>
#define size 100
using namespace std;
int main()
{
    int A[size],n,t,i,j,num,c=0;
    cin>>t;
    j=1;
    while(j<=t)
    {
        cin>>n;
        for(i=0;i<n;i++)
        {
            cin>>A[i];
        }
        cin>>num;
        for(i=0;i<n;i++)
        {
            if(A[i]== num)
            {
                c=1;
                cout<<"Present "<<i+1<<"\n";
            }
        }
        if(c==0)
        {
            cout<<"Not Present "<<i<<"\n";
        }
        t=t-1;
    }
    return 1;
}
