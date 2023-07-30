Question Link: https://leetcode.com/problems/intersection-of-two-arrays/

class Solution {
public:
    vector<int> intersection(vector<int>& a, vector<int>& b) {
        int n=a.size(), m=b.size();
        vector<int> ans;
        
        set<int> st(a.begin(),a.end());
        for(int i=0;i<m;i++){
            if(st.find(b[i])!=st.end()){
                ans.push_back(b[i]);
                st.erase(b[i]);
            }
        }
        
        return ans;
    }
};
