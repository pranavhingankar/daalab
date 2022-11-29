#include<bits/stdc++.h>
#define ll long long int
using namespace std ;

int main(){
   vector<ll>v = {0,1,4,1,2,4,2} ;
    ll n = v.size() ;
    map<ll,ll>mp ;
   for (ll i = 0; i < n; i++)
   {
        mp[v[i]]++ ;
   }
   
   ll maxi = INT_MIN , ans = -1 ;
   for (auto it : mp)
   {
        if(maxi < it.second) ans = it.first ;
   }

   cout<<ans<<endl;
   
}
