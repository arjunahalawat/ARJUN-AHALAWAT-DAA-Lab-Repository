#include <iostream> //using Quick Sort
using namespace std;
int partition(int A[], int lb, int ub)
{
    int piv=A[ub],i=lb - 1,temp;
    for(int j=lb;j<ub;j++)
    {
        if(A[j]<=piv)
        {
            i++;
            temp=A[i];
            A[i]=A[j];
            A[j]=temp;
        }
    }
    temp=A[i+1];
    A[i+1]=A[ub];
    A[ub]=temp;
    return i + 1;
}
void qSort(int A[],int lb,int ub)
{
    if(lb<ub)
    {
        int p=partition(A,lb,ub);
        qSort(A,lb,p-1);
        qSort(A, p + 1, ub);
    }
}
void duplicates(int A[],int n)
{
    for(int i=0;i<n-1;i++)
    {
        if(A[i]==A[i+1])
        {
            cout << "YES\n";
            return;
        }
    }
    cout<<"NO\n";
}
int main()
{
    int i,t,n;
    cin>>t;
    while(t)
    {
        cin>>n;
        int *A=new int[n];
        for (i=0;i<n;i++)
        {
            cin>>A[i];
        }
        qSort(A,0,n-1);
        duplicates(A,n);
        t--;
    }
}
