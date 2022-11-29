#include<bits/stdc++.h>
#define ll long long int
using namespace std ;

int main(){

   vector<pair<ll,ll>>v ;
    v.push_back({65,100}) ; 
    v.push_back({70,150}) ; 
    v.push_back({56,90}) ; 
    v.push_back({75,190}) ; 
    v.push_back({60,95}) ; 
    v.push_back({68,110}) ; 

   sort(v.begin(),v.end()) ;

   ll n = v.size() ;

   int lis[n] ;

   for (ll i = 0; i < n; i++)
   {
        lis[i] = 1 ;
   }
   

   for (ll i = 1; i < n; i++)
   {
        for (ll j = 0; j < i; j++)
        {
                if(v[i].second > v[j].second && lis[i]<lis[j]+1) 
                  lis[i] = lis[j]+1 ;
        }
        
   }

   ll maxi = INT_MIN ;
   for (ll i = 0; i < n; i++)
   {
        if(maxi < lis[i]) 
          maxi = lis[i] ;
   }
   
   cout<<maxi<<endl;
}
