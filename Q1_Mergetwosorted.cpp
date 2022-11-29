#include <iostream>
using namespace std;

int main()
{
    int n, a, b;
    cin >> a >> b;
    int A[a + b];
    int B[b];
    for (int i = 0; i < a; i++)
        cin >> A[i];
    for (int i = 0; i < b; i++)
        cin >> B[i];
    for (int i = a; i < a + b; i++)
        A[i] = 0;

    int i = a - 1, j = b - 1, k = a + b - 1;
    while (i >= 0 && j >= 0)
    {
        if (A[i] < B[j])
        {
            A[k] = B[j];
            k--;
            j--;
        }
        else
        {
            A[k] = A[i];
            A[i] = 0;
            k--;
            i--;
        }
    }
    while (j >= 0)
    {
        A[k] = B[j];
        k--;
        j--;
    }

    for (int i = 0; i < a + b; i++)
        cout << A[i] << " ";
    return 0;
}
