Question Link : https://leetcode.com/problems/find-first-and-last-position-of-element-in-sorted-array/

class Solution {
public:
    
    int firstOccurance(vector<int>& a, int target){
        int n=a.size();
        int l=0, r=n-1;
        while(l<r){
            int m=l+(r-l)/2;
            
            if(a[m]>=target){
                r=m;
            }else{
                l=m+1;
            }
        }
        return (a[l]==target ? l:-1);
    }
    
    int lastOccurance(vector<int>& a, int target){
        int n=a.size();
        int l=0, r=n-1;
        while(l<r){
            int m=l+(r-l+1)/2;
            if(a[m]<=target){
                l=m;
            }else{
                r=m-1;
            }
        }
        return (a[l]==target ? l:-1);
    }
    
    vector<int> searchRange(vector<int>& a, int target) {
        if(a.size()==0) return {-1,-1};
        
        int first=firstOccurance(a,target);
        int last=lastOccurance(a,target);
        return {first,last};
    }
};
