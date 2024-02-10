#include <iostream>
using namespace std;
void indices(int *A,int n)
{
    for (int k=n-1;k>= 0;k--)
    {
        int i = 0, j = k-1;
        while (i < j)
        {
            int s = A[i] + A[j];
            if (s==A[k])
            {
                cout<<i<< " " <<j<< " " <<k<< endl;
                return;
            }
            else if (s<A[k])
            {
                i++;
            }
            else
            {
                j--;
            }
        }
    }
    cout<<"No sequence found.\n";
}
int main()
{
    int *A,n,t;
    cin >>t;
    while (t)
    {
        cin >> n;
        A = new int[n];
        for (int i = 0; i < n; i++)
        {
            cin >> *(A+ i);
        }
        indices(A,n);
        delete[] A;

        t--;
    }
    return 0;
}
