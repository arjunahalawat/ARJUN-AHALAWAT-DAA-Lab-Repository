#include <iostream>     // Q1 solved using predefined functions
#include <algorithm>
using namespace std;

void keys(int A[], int n, int key)
{
    int lb = lower_bound(A, A+ n, key) - A;
    int ub = upper_bound(A, A + n, key) - A;
    int copy = lb - ub;
    cout << key << copy << endl;
}
int main()
{
    int n, *A, t, key;
    cin >> t;
    while (t)
    {
        cin >> n;
        A = new int[n];
        for (int i = 0; i < n; i++)
        {
            cin >> *(A + i);
        }
        cin >> key;

        keys(A, n, key);

        delete[] A;

        t--;
    }
    return 0;
}
