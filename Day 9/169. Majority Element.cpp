Question Link: https://leetcode.com/problems/majority-element/

class Solution {
public:
    int majorityElement(vector<int>& a) {
        int n=a.size();
        
        int majorit_val=a[0];
        int freq=1;
        
        for(int i=1;i<n;i++){
            if(majorit_val==a[i]){
                freq++;
            }else{
                freq--;
            }
            if(freq==0){
                majorit_val=a[i];
                freq=1;
            }
        }
        return majorit_val;
    }
};
