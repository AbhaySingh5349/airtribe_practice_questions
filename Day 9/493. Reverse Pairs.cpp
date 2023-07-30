Question Link: https://leetcode.com/problems/reverse-pairs/

class Solution {
public:
    
    int merge(vector<int>& a, int l, int r){
        int m=l+(r-l)/2;
        
        // we need to count earlier, as while merging step, we cannot say 'ith or jth' element to be added first
        // eg. [5,7,8,9] [3,4,5]
        int c=0;
        int i=l ,j=m+1;
        while(i<=m && j<=r){
            while(i<=m && a[i]<=2*(long)a[j]) i++;
            c+=(m+1-i);
            j++;
        }
        
        vector<int> v;
        
        i=l, j=m+1;
        while(i<=m && j<=r){
            if(a[i]<=a[j]){
                v.push_back(a[i++]);
            }else{
                v.push_back(a[j++]);
            }
        }
        while(i<=m) v.push_back(a[i++]);
        while(j<=r) v.push_back(a[j++]);
        
        for(int i=l;i<=r;i++) a[i]=v[i-l];
        
        return c;
    }
    
    int mergesort(vector<int>& a, int l, int r){
        if(l==r) return 0;
        
        int c=0;
        int m=l+(r-l)/2;
        
        c+=mergesort(a,l,m);
        c+=mergesort(a,m+1,r);
        c+=merge(a,l,r);
        
        return c;
    }
    
    int reversePairs(vector<int>& a) {
        int n=a.size();
        
        return mergesort(a,0,n-1);
    }
};
