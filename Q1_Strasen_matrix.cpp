#include<bits/stdc++.h>
using namespace std;
int main() {
   int product[10][10], r1=3, c1=3, r2=3, c2=3, i, j, k;
   int a[3][3] = {
      {2, 4, 1},
      {2, 3, 9},
      {3, 1, 8}
   };
   int b[3][3] = {
      {1, 2, 3},
      {3, 6, 1},
      {2, 4, 7}
   };
   if (c1 != r2) {
      cout<<"Multiplication not possible !!! ";
   } else {
      

     vector<vector<int>>product(3,vector<int>(3,0));

      for(i=0; i<r1; ++i)
         for(j=0; j<c2; ++j)
            for(k=0; k<c1; ++k) {
               product[i][j]+=a[i][k]*b[k][j];
            }
     
      for(i=0; i<r1; ++i) {
         for(j=0; j<c2; ++j)
            cout<<product[i][j]<<" ";
         cout<<endl;
      }
   }
   return 0;
}
