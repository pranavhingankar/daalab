#include <bits/stdc++.h>
using namespace std;
#define int long long
using pii = pair<int,int>;
using dii = pair<double,pair<int,int>>;

bool cmp1(pii A,pii B)
{
    if(A.first > B.first) return 1;
    if(A.first < B.first) return 0;
    return A.second <= B.second;
}

bool cmp2(pii A,pii B)
{
    if(A.first > B.first) return 0;
    if(A.first < B.first) return 1;
    return A.second >= B.second;
}

bool cmp3(dii a,dii b)
{
    if(a.first > b.first) return 1;
    if(a.first < b.first) return 0;
    return a.second.first >= b.second.first;
}

int largestProfitStrategy(vector<int> weight,vector<int> val,int W)
{
    vector<pair<int,int>> v;
    for(int i=0;i<weight.size();i++)v.push_back({val[i],weight[i]});

    sort(v.begin(),v.end(),cmp1);

    int profit = 0;
    for(int i=0;i<v.size();i++)
    {
        if(W >= v[i].second)
        {
            profit += v[i].first;
            W -=  v[i].second;
        }
        else
        {
            profit += (int)(((double) W / v[i].second)*v[i].first);
        }
    }
    return profit;
}

int smallestWeightStrategy(vector<int> weight,vector<int> val,int W)
{
    vector<pair<int,int>> v;
    for(int i=0;i<weight.size();i++)v.push_back({weight[i],val[i]});

    sort(v.begin(),v.end(),cmp2);

    int profit = 0;
    for(int i=0;i<v.size();i++)
    {
        if(W >= v[i].first)
        {
            profit += v[i].second;
            W -= v[i].first;
        }
        else
        {
            profit += (int)(((double) W / v[i].first)*v[i].second);
        }
    }
    return profit;
}

int ratioStrategy(vector<int> weight,vector<int> val,int W)
{
    vector<dii> v;
    for(int i=0;i<weight.size();i++)v.push_back({((double)val[i]/weight[i]),{val[i],i}});

    sort(v.begin(),v.end(),cmp3);

    int profit = 0;
    for(int i=0;i<v.size();i++)
    {
        int index = v[i].second.second;

        int w = weight[index];
        int value = val[index];
        if(W >= w)
        {
            profit += value;
            W -= w;
        }
        else
        {
            profit += (int)(((double) W / w)*value);
        }
    }
    return profit;
}

int32_t main()
{
    #ifndef ONLINE_JUDGE
            freopen("input.txt","r",stdin);
            freopen("output.txt","w",stdout);
    #endif
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    int n,m;
    cin >> n >> m;

    vector<int> weight(n);
    vector<int> val(n);

    for(int i=0;i<n;i++)cin >> weight[i];
    for(int i=0;i<n;i++)cin >> val[i];

    cout << "Largest Profit Staretegy : " << largestProfitStrategy(weight,val,m) << '\n';
    
    cout << "Smallest weight Staretegy : " << smallestWeightStrategy(weight,val,m) << '\n';

    cout << "Largest Profit-to-weight ration Staretegy : " << ratioStrategy(weight,val,m);
    
    return 0;
}
