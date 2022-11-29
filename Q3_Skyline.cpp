#include <bits/stdc++.h>
using namespace std;
 
vector<pair<int, int> >
createSkyline(vector<vector<int> >& buildings)
{
 
    int N = buildings.size();
 
    vector<pair<int, int> > wall;
 
    int left, height, right;
    for (int i = 0; i < N; i++) {
 
        left = buildings[i][0];
 
        height = buildings[i][1];
 
        right = buildings[i][2];
 
 
        wall.push_back({ left, -height });
 
        wall.push_back(
            make_pair(right, height));
    }
 
    sort(wall.begin(), wall.end());
 
    vector<pair<int, int> > skyline;
 
    multiset<int> leftWallHeight = { 0 };
 
    int top = 0;
 
    for (auto w : wall) {
 
        if (w.second < 0) {
 
            leftWallHeight.insert(-w.second);
        }
 
        else {
 
            leftWallHeight.erase(
                leftWallHeight.find(w.second));
        }
 
        if (*leftWallHeight.rbegin() != top) {
 
            top = *leftWallHeight.rbegin();
            skyline.push_back(
                make_pair(w.first, top));
        }
    }
 
    return skyline;
}
 
void printSkyline(
    vector<vector<int> >& buildings)
{
 
    vector<pair<int, int> > skyline
        = createSkyline(buildings);
 
    cout << "Skyline for given"
         << " buildings:\n{";
 
    for (auto it : skyline) {
 
        cout << "{" << it.first << ", "
             << it.second << "} ";
    }
    cout << "}";
}
 
int main()
{
    vector<vector<int> > buildings;
 
    buildings = { { 1, 11, 5 }, { 2, 6, 7 },
                  { 3, 13, 9 }, { 12, 7, 16 },
                  { 14, 3, 25 }, { 19, 18, 22 },
                  { 23, 13, 29 }, { 24, 4, 28 } };
 
    printSkyline(buildings);
    return 0;
}
