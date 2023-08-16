Question Link : https://leetcode.com/problems/unique-binary-search-trees/

class Solution {
public:
    int numTrees(int n) {
        vector<int> dp(n+1,0);
        dp[0]=dp[1]=1;
        
        for(int nodes=2;nodes<n+1;nodes++){
            for(int left_nodes=0;left_nodes<nodes;left_nodes++){
                int right_nodes = (nodes-1) - left_nodes;
                
                dp[nodes] += dp[left_nodes]*dp[right_nodes];
            }
        }
        
        return dp[n];
    }
};
