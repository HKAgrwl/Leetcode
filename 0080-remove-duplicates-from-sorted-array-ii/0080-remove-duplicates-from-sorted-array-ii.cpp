class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if(nums.size()==1) return 1;
        vector<int> temp;
        temp.push_back(nums[0]);
        temp.push_back(nums[1]);
        int x = 1;
        for(int i=2;i<nums.size();i++){
            if(temp[x-1]== nums[i] && temp[x]==nums[i]){
                continue;
            }
            temp.push_back(nums[i]);
            x++;
            
        }
        for(int i =0;i<temp.size();i++){
            nums[i] = temp[i];
        }
        // cout<<temp.size()<<endl;
        return temp.size();
    }
};