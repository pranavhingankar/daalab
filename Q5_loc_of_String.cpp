#include <bits/stdc++.h>
using namespace std;

// Compare two string equals are not
int compareStrings(string str1, string str2)
{
    int i = 0;
    while (str1[i] == str2[i] && str1[i] != '\0')
        i++;
    if (str1[i] > str2[i])
        return -1;

    return (str1[i] < str2[i]);
}

int searchStr(string arr[], string str, int first,
                                        int last)
{
    if (first > last)
        return -1;

    // Move mid to the middle
    int mid = (last+first)/2;

    // If mid is empty , find closest non-empty string
    if (arr[mid].empty())
    {

        int left = mid - 1;
        int right = mid + 1;
        while (true)
        {
            if (left < first && right > last)
                return -1;
            if (right<=last && !arr[right].empty())
            {
                mid = right;
                break;
            }
            if (left>=first && !arr[left].empty())
            {
                mid = left;
                break;
            }
            right++;
            left--;
        }
    }

    // If str is found at mid
    if (compareStrings(str, arr[mid]) == 0)
        return mid;

    // If str is greater than mid
    if (compareStrings(str, arr[mid]) < 0)
        return searchStr(arr, str, mid+1, last);

    // If str is smaller than mid
    return searchStr(arr, str, first, mid-1);
}

int main()
{
    // Input arr of Strings.
    string arr[] = {"at", "", "", "ball", "", "", "car", "", "", "dad", "",""};

    // input Search String
    string str = "car";
    int n = sizeof(arr)/sizeof(arr[0]);
    cout<<n<<endl;
    cout <<  searchStr(arr, str, 0, n-1);
    return 0;
}
