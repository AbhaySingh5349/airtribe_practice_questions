Question Link : https://leetcode.com/problems/longest-happy-prefix/

class Solution {
public:
    
    // len = j+1
    // s[0,j] == s[i-len+1:i]
    
    string longestPrefix(string s) {
        int n=s.length();
        
        vector<int> table(n,-1);
        
        int i=1, j=0;
        while(i<n){
            if(s[i]==s[j]){
                table[i]=j;  // we got a prefix in string from [0,i] ending in j that is also a suffix ending in i
                i++, j++;
            }else{
                if(j>0){
                    j=table[j-1]; // since we had faliure at idx j, we go to prefix for which (j-1) was suffix 
                    j++;
                }else{
                    i++;
                }
            }
        }
        int idx=table[n-1];
    
        string ans="";
        if(idx!=-1){
            ans=s.substr(0,idx+1);
        }
        return ans;
    }
};
