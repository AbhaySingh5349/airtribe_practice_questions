Question Link: https://leetcode.com/problems/most-common-word/

class Solution {
public:
    
    string mostCommonWord(string p, vector<string>& banned) {
        set<string> st(banned.begin(), banned.end());
        
        map<string, int> mp;
        
        int n=p.length();
        int i=0;
        while(i<n){
            string s="";
            while(i<n && isalpha(p[i++])) s += tolower(p[i-1]);
            
            if(s.length() > 0 && st.find(s) == st.end()) mp[s]++;
        }
        
        int max_f=0;
        string ans="";
        
        for(auto it=mp.begin();it!=mp.end();it++){
            if(it->second > max_f){
                max_f=it->second;
                ans=it->first;
            }
        }
        
        return ans;
    }
};
