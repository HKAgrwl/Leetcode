class Solution {
public:
    int trap(vector<int>& height) {
        int len = height.size();
        int left[len];
        int right[len];
        int sum,leftMax,rightMax;
        
        sum=leftMax=rightMax=0;
        
        for(int i=0;i<=len-1;i++){
            if(height[i]>leftMax){
                left[i]=leftMax;
                leftMax = height[i];
                continue;
            }
            left[i]=leftMax;
        }
        for(int i=len-1;i>=0;i--){
            if(height[i] > rightMax){
                right[i]=rightMax;
                rightMax = height[i];
                continue;
            }
            right[i] = rightMax;
        }
        
        for(int i=0;i<len;i++){
            cout<<left[i]<<" ";
            int interim= min(left[i],right[i])-height[i];
            if(interim>0){
                sum+=interim;
            }
        }
        return sum;
    }
};