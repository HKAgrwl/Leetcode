class Solution {
public:
    int maxArea(vector<int>& height) {
        int start=0;
        int end=height.size()-1;
        int maxVol=0;
        int vol;
        while(start<end){
            vol = (end-start) * min(height[start],height[end]);
            cout<<vol<<" ";
            maxVol = max(maxVol,vol);
            if(height[start]<height[end]){
                start++;
            }else{
                end--;
            }
        }
        return maxVol;
    }
};