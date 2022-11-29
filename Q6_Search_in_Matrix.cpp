#include <bits/stdc++.h>
#define ll long long int
using namespace std;

int main()
{

    vector<vector<int>> matrix = {{1, 4, 7, 11, 15}, {2, 5, 8, 12, 19}, {3, 6, 9, 16, 22}, {10, 13, 14, 17, 24}, {18, 21, 23, 26, 30}};
    int target = 5;
    int n = matrix.size();
    int m = matrix[0].size();
    int i = 0, j = m - 1;

    while (i < n && j >= 0)
    {
        if (matrix[i][j] == target){
            cout<<i<<" "<<j<<endl;
            return 0;
        }
        else if (matrix[i][j] < target)
            i++;
        else
            j--;
    }

    cout<<"Not Found"<<endl;
    return 0;
}
