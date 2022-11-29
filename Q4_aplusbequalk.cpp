#include<bits/stdc++.h>
#define ll long long int
using namespace std ;

int main(){
  vector<ll>v1 = {1,2,3,4,5,6};
  vector<ll>v2 = {1,2,3,4,5,6};

  map<int,int>mp ;

  ll k = 6 ;
  ll n = v1.size() ;
  for(int i = 0 ; i < n ; i++) mp[v2[i]] = i ;

  for (ll i = 0; i < n; i++)
  {
        if(mp.find(k-v1[i]) != mp.end()) cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
  }
  
}
