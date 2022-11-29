#include <iostream>
using namespace std;
void merge(int arr[], int start, int mid, int end)
{
    int nl = mid - start + 1;
    int nr = end - mid;
    int al[nl], ar[nr];
    for (int i = 0; i < nl; i++)
        al[i] = arr[start + i];
    for (int i = 0; i < nr; i++)
        ar[i] = arr[mid + 1 + i];
    int i = 0, j = 0, mer = start;
    while (i < nl && j < nr)
    {
        if (al[i] <= ar[j])
        {
            arr[mer] = al[i];
            i++;
        }
        else
        {
            arr[mer] = ar[j];
            j++;
        }
        mer++;
    }
    while (i < nl)
    {
        arr[mer] = al[i];
        mer++;
        i++;
    }
    while (j < nr)
    {
        arr[mer] = ar[j];
        mer++;
        j++;
    }
}
void mergesort(int arr[], int start, int end)
{
    if (start >= end)
        return;
    int mid = (start + end) / 2;
    mergesort(arr, start, mid);
    mergesort(arr, mid + 1, end);
    merge(arr, start, mid, end);
}
int main()
{
    int n, a[n];
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> a[i];
    mergesort(a, 0, n - 1);
    for (int i = 0; i < n; i++)
        cout << a[i] << " ";
    int flag = 1;
    for (int i = 1; i < n; i++)
    {
        if (a[i] == a[i - 1])
        {
            cout << "\ntrue" << endl;
            flag = 0;
            break;
        }
    }
    if (flag)
        cout << "\nfalse" << endl;
    return 0;
}
