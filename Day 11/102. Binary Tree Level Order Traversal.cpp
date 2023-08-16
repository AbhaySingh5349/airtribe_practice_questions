Question Link : https://leetcode.com/problems/binary-tree-level-order-traversal/

class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        
        queue<TreeNode*> q;
        if(root!=NULL) q.push(root);
        
        while(q.size()>0){
            int size=q.size();
            vector<int> sub;
            while(size--){
                TreeNode* cur=q.front();
                q.pop();
                
                sub.push_back(cur->val);
                
                if(cur->left) q.push(cur->left);
                if(cur->right) q.push(cur->right);
            }
            ans.push_back(sub);
        }
        return ans;
    }
};
