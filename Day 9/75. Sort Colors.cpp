Question Link: https://leetcode.com/problems/sort-colors/

class Solution {
public:
    void sortColors(vector<int>& a) {
        int n=a.size();
        
        // Dutch National Flag algo 
        // [0,i] => 0's , [i+1,j-1] => 1's, [j,k] => undefined, [k+1,n-1]: 2's
        
        int i=-1, j=0, k=n-1;
        while(j<=k){
            if(a[j] == 0){
                i++;
                swap(a[i],a[j]);
                j++;
            }else if(a[j] == 2){
                swap(a[j],a[k]);
                k--;
            }else{
                j++;
            }
        }
    }
};
