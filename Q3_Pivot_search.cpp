#include <bits/stdc++.h>
using namespace std;

int finding_pivot(vector<int> arr)
{
    int start = 0;
    int end = arr.size() - 1;

    while (start < end)
    {
        int mid = start + (end - start) / 2;
        if (arr[0] <= arr[mid])
            start = mid + 1;
        else
            end = mid;
    }
    cout << "Starting Element is: "<<start<<"\n";
    return start;
}
int fun(vector<int> arr, int start, int end, int target)
{
    while (start <= end)
    {
        int mid = start + (end - start) / 2;
        if (arr[mid] == target)
        {
            cout << "Element is present at index"<<arr[mid]<<"->";
            return mid;
        }
        else if (arr[mid] < target)
            start = mid + 1;
        else
            end = mid - 1;
    }

    return -1;
}

int search(vector<int> &arr, int target)
{
    int l = arr.size();
    int k = -1;
    if (l == 1 && arr[0] == target)
        return 0;
    else if (l == 1 && arr[0] != target)
        return -1;
    int p = finding_pivot(arr);

    if (target >= arr[0] && target <= arr[p - 1])
        k = fun(arr, 0, p - 1, target);
    else if (target >= arr[p] && target <= arr[l - 1])
        k = fun(arr, p, l - 1, target);

    return k;
}

int main()
{
    int n, target;
    vector<int> arr;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> target;
        arr.push_back(target);
    }
    cin >> target;
    cout << search(arr, target);
    return 0;
}
