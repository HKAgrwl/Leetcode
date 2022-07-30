class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int p1=0;
        int p2=0;
        vector<int> finals ;
        while(p1<nums1.size() && p2<nums2.size()){
            if(nums1[p1]<nums2[p2]){
                finals.push_back(nums1[p1]);
                p1++;
            }else{
                finals.push_back(nums2[p2]);
                p2++;
            }
        }
        while(p1<nums1.size()){
            finals.push_back(nums1[p1]);
            p1++;
        }
        while(p2<nums2.size()){
            finals.push_back(nums2[p2]);
            p2++;
        }
        double median;
        int size = finals.size();
        if(size%2!=0){
            median = finals[size/2];
        }else{
            median = finals[(size-1)/2]+finals[(size+1)/2];
            median=median/2;
        }
        return median;
    }
};