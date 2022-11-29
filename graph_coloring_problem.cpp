#include<bits/stdc++.h>
using namespace std;


#define N 4

void print(int color[])
{
  cout << "Solution Exists: \nColors:\n";
  for (int i = 0; i < N; i++)
    cout << " " << color[i];
  cout << "\n";
}

bool isSafe(int graph[N][N], int color[])
{
  for (int i = 0; i < N; i++)
    for (int j = i + 1; j < N; j++)
      if (graph[i][j] && color[j] == color[i])
        return false;
  return true;
}


bool colorGraph(int graph[N][N], int m, int i,
                int color[N])
{
  if (i == N) {

    if (isSafe(graph, color)) {

      print(color);
      return true;
    }
    return false;
  }

  for (int j = 1; j <= m; j++) {
    color[i] = j;

    if (colorGraph(graph, m, i + 1, color))
      return true;

    color[i] = 0;
  }

  return false;
}



int main()
{
  /* Create following graph and
  test whether it is 3 colorable
  (3)---(2)
  | / |
  | / |
  | / |
  (0)---(1)
  */
#ifndef ONLINE_JUDGE
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
#endif
  int graph[N][N] = {
    { 0, 1, 1, 1 },
    { 1, 0, 1, 0 },
    { 1, 1, 0, 1 },
    { 1, 0, 1, 0 },
  };
  int m = 3;

  int color[N];

  // coloring intitially as 0
  for (int i = 0; i < N; i++)
    color[i] = 0;

  if (!colorGraph(graph, m, 0, color))
    cout << "Solution does not exist";

  return 0;
}

