#include <iostream>
using namespace std;
int partition(int A[], int lb, int ub)
{
    int pivot=A[ub];
    int i=lb-1,temp;
    for(int j=lb;j<ub;j++)
    {
        if(A[j]<=pivot)
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
    return i+1;
}
void qSort(int A[], int lb, int ub)
{
    if (lb < ub)
    {
        int p = partition(A,lb,ub);
        qSort(A, lb, p-1);
        qSort(A, p + 1, ub);

    }
}

int main()
{
    int n,t;
    cin >> t;
    while(t)
    {
        cin>>n;
        int *A = new int[n];
        for(int i = 0; i < n; i++)
        {
            cin >> A[i];
        }
        qSort(A, 0, n - 1);
        for (int i = 0; i < n; i++)
        {
            cout << A[i] << " ";
        }
        cout << endl;
        t--;
    }
    return 0;
}
