Question Link: https://leetcode.com/problems/find-common-characters/

class Solution {
public:
    vector<string> commonChars(vector<string>& words) {
        int n=words.size();
        
        vector<vector<int>> freq(n+1, vector<int>(26,0));
        for(int i=0;i<n;i++){
            string s=words[i];
            for(char ch : s) freq[i][ch-'a']++;
        }
        
        vector<string> ans;
        for(int i=0;i<26;i++){
            int f=101;
            for(int j=0;j<n;j++) f=min(f,freq[j][i]);
            
            char ch = (char)(i+'a');
            std::string s(1, ch);
            
            if(f>0) ans.insert(ans.end(), f, s);
        }
        
        return ans;
    }
};
