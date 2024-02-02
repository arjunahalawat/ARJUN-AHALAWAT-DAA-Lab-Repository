#include <iostream>
using namespace std;
void fun(int *arr, int l, int u, int key, int &c)
{
    int mid = l + (u - l) / 2;
    c++;
    if (u >= l)
    {
        if (*(arr + mid) == key)
        {
            cout << "Present " <<c<< endl<< endl;
            return;
        }
        if (*(arr + mid) > key)
        {
            fun(arr, l, mid - 1, key, c);
        }
        if (*(arr + mid) < key)
        {
            fun(arr, mid + 1, u, key,c);
        }
    }
    else
    {
    cout << "Not Present " <<c-1 << endl<< endl;
    }
}
int main()
{
int n, *arr, testCase, key;
cin >> testCase;
while (testCase)
{
cin >> n;
arr = new int[n];
for (int i = 0; i < n; i++)
{
cin >> *(arr + i);
}
cin >> key;
int comparison = 0;
fun(arr, 0, n - 1, key, comparison);
delete[] arr;
testCase--;
}
return 0;
}
