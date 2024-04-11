#include<iostream>
#define size 100
using namespace std;
int same(int fa[],int m,int sa[],int n,int T[])
{
    int k=0,i=0,j=0;
    while(i<m&&j<n)
    {
        if(fa[i]==sa[j])
        {
            T[k]=fa[i];
            k++;
            i++;
            j++;
        }
        else if(fa[i]<sa[j])
        {
            i++;
        }
        else
        {
            j++;
        }
    }
    return k;
}

int main()
{
    int m,n,i,k,T[size];
    cin>>m;
    int fa[m];
    for(i=0;i<m;i++)
    {
        cin>>fa[i];
    }
    cin>>n;
    int sa[n];
    for(i=0;i<m;i++)
    {
        cin>>sa[i];
    }
    k = same(fa,m,sa,n,T);
    for(i=0;i<k;i++)
    {
        cout<<T[i]<<" ";
    }
    return 0;
}
