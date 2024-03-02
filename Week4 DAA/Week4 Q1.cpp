#include<iostream>
using namespace std;
void merging(int A[],int lb,int mid,int ub)
{
    int T[ub-lb+1];
    int i=lb,j=mid+1,k=0;
    while(i<=mid&&j<=ub)
    {
        if(A[i]<=A[j])
        {
            T[k]=A[i];
            i++;
        }
        else if (A[i]>A[j])
        {
            T[k]=A[j];
            j++;
        }
        k++;
    }
    while(i<=mid)
    {
        T[k]=A[i];
        i++;
        k++;
    }
    while(j<=ub)
    {
        T[k]=A[j];
        j++;
        k++;
    }
    for(int l=0;l<k;l++)
    {
        A[lb+l]=T[l];
    }
}
void mergeSort(int A[],int lb,int ub)
{
    if(lb<ub)
    {
        int  mid=lb+(ub-lb)/2;
        mergeSort(A,lb,mid);
        mergeSort(A,mid+1,ub);

        merging(A,lb,mid,ub);
    }
}
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
        mergeSort(A,0,n-1);
        for (int i = 0; i < n; i++)
        {
            cout<<A[i]<< " ";
        }
        cout<<endl;
        t--;
    }
    return 0;
}
