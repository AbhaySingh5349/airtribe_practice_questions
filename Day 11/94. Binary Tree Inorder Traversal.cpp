Question Link : https://leetcode.com/problems/binary-tree-inorder-traversal/

// Recursion
class Solution {
public:
    void solve(TreeNode* root, vector<int> &ans){
        if(root==NULL) return;
        solve(root->left,ans);
        ans.push_back(root->val);
        solve(root->right,ans);
    }
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> ans;
        solve(root,ans);
        return ans;
    }
};

// Iterative
class Solution {
public:
    
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> ans;
        
        stack<TreeNode*> st;
        TreeNode* cur=root;
        
        while(cur!=NULL || st.size()>0){
            if(cur!=NULL){
                st.push(cur);
                cur=cur->left;
            }else{
                cur = st.top();
                st.pop();
                
                ans.push_back(cur->val);
                cur=cur->right;
            }
        }
        
        return ans;
    }
};
