Question Link : https://leetcode.com/problems/serialize-and-deserialize-binary-tree/

class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        if(root==NULL) return "$";
        
        string s="";
        s=to_string(root->val)+",";
        
        s += serialize(root->left)+",";
        s += serialize(root->right);
        
        return s;
    }
    
    int getVal(string s){
        int val=0;
        
        bool isNeg = false;
        int i=0;
        if(s[0] == '-') isNeg=true, i++;
        
        while(i<s.length()) val = val*10 + (s[i++]-'0');
        
        return (isNeg ? -val:val);
    }
    
    vector<string> splitString(string input){
        std::stringstream ss(input); // Create a stringstream from the input string
        string sub_str=""; 
        vector<string> tokens; // Vector to store all substrings

        // Loop through the stringstream to extract substrings using ',' as the delimiter
        while (std::getline(ss, sub_str, ',')) {
            tokens.push_back(sub_str); // Store each substring in the vector
        }
        
        return tokens;
    }

    // Decodes your encoded data to tree.
    
    TreeNode *solve(vector<string> &arr, int &idx){
        int n=arr.size();
        
        if(idx >= n || arr[idx]=="$"){
            idx++;
            return NULL;
        }
        
        TreeNode *root = new TreeNode(getVal(arr[idx++]));
        root->left = solve(arr, idx);
        root->right = solve(arr, idx);
        
        return root;
    }
    
    TreeNode* deserialize(string s) {
        vector<string> arr = splitString(s);
        cout<<s<<" ";
        int idx=0;
        return solve(arr, idx);
    }
};
