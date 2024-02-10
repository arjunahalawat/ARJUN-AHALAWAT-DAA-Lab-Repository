#include <iostream>
using namespace std;

int firstFind(int A[], int n, int key)
{
    int lb = 0,ub = n - 1,ans = -1;

    while (lb<=ub)
    {
        int mid = lb + (ub - lb) / 2;

        if (A[mid] == key)
        {
            ans = mid;
            ub = mid - 1;
        }
        else if (A[mid] < key)
            lb = mid + 1;
        else
            ub = mid - 1;
    }

    return ans;
}
int lastFind(int A[], int n, int key)
{
    int lb = 0,ub = n - 1,ans = -1;
    while (lb<=ub)
    {
        int mid = lb+(ub - lb) / 2;
        if (A[mid] == key)
        {
            ans = mid;
            lb = mid + 1;
        }
        else if (A[mid] < key)
            lb= mid + 1;
        else
            ub= mid - 1;
    }
    return ans;
}
void keyCopies(int A[], int n, int key)
{
    int first = firstFind(A, n, key);

    if (first != -1)
    {
        int last = lastFind(A, n, key);
        int copies = last - first + 1;

        cout << key << " - " << copies << endl;
    }
    else
    {
        cout << "Key not present\n";
    }
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

        keyCopies(A, n, key);

        delete[] A;

        t--;
    }
    return 0;
}
