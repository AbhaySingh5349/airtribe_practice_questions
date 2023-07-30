Question Link: https://leetcode.com/problems/merge-sorted-array/

class Solution {
public:
    
    void merge(vector<int> &a, int m, vector<int> &b, int n) {
        int i=m-1, j=n-1, k=m+n-1;
        while(i>=0 || j>=0){
            int x = (i>=0 ? a[i]:INT_MIN), y = (j>=0 ? b[j]:INT_MIN);
            
            if(x>=y){
                a[k--]=x;
                i -= (i>=0);
            }else{
                a[k--]=y;
                j -= (j>=0);
            }
        }
    }
};
