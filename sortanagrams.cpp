#include<bits/stdc++.h>
using namespace std;

vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> ans;
        int n = strs.size();
        unordered_map<string,vector<string>> mp;
        
        for(int i= 0;i<n;i++){
            string temp= strs[i];
            sort(strs[i].begin(),strs[i].end());
            mp[strs[i]].push_back(temp);
        }
        
        for(auto it = mp.begin();it!=mp.end();++it){
            ans.push_back(it->second);
            
        }
        return ans;
    }

int main(){
    vector<string> strs;
    vector<vector<string>> ans;
    int n;
    string s;
    cin>>n;
    for(int i = 0;i<n;i++){
        cin>>s;
        strs.push_back(s);
    } 
    ans = groupAnagrams(strs);
    for(int i = 0;i<ans.size();i++){
        for(int j = 0;j<ans[i].size();j++){
            cout<<ans[i][j]<<" ";
        }
        cout<<endl;
    }
    return 0;
}
