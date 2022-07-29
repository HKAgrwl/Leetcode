class Solution {
public:
    
    // for the first occurence we will check in <mid also if our nums[mid]==target, so the condition is hi=mid-1 in when our nums[mid]==target 
    
    // for the second occurence we will only check in right half of mid,which lo=mid+1 in nums[mid]==target
    
    int occurence(vector<int>&nums,int k,int target){
        int res=-1;
        int lo=0;
        int hi=nums.size()-1;
        while(lo<=hi){
            int mid=lo+(hi-lo)/2;
            
            if(nums[mid]==target) {
                res=mid;
                if(k==1){
                hi=mid-1;}
                else{
                    lo=mid+1;
                }
            }
            if(nums[mid]<target){
                lo=mid+1;
            }
            else if(nums[mid]>target) /* else condition was unnecessarily decreasing hi to mid-1 in case of [3,3,3] target =3 so that is why i did else if ....*/
                hi=mid-1;
                
            }
        
        return res;
        
    }
    
    
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int>store;
        // if(nums.size()==0) return {-1,-1};
        // if(nums.size()==1 && target==nums[0]) return{0,0};
        // if(nums.size()==1 && target!=nums[0]) return {-1,-1};
        
        int first=occurence(nums,1,target);
        int last=occurence(nums,2,target);
        store.push_back(first);
        store.push_back(last);
        return store;
      
    }
};