Question Link : https://leetcode.com/problems/longest-common-prefix/

class Solution {
public:
    string longestCommonPrefix(vector<string>& v) {
        string ans=v[0];
        int i,j, n = v.size();
        
        for(i=1;i<n;i++){
            string temp="";
            for(j=0;j<min(ans.length(),v[i].length());j++){
                if(v[i][j]==ans[j]){
                    temp+=ans[j];
                }else{
                    break;
                }
            }
            ans=temp;
        }
        return ans;
    }
};
