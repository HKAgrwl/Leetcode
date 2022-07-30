class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        vector<int> sampleSpace = helper(matrix,target);
        int start = 0;
        int end = sampleSpace.size()-1;
        while(end>=start){
            int mid = (start+end)/2;
            if(sampleSpace[mid]==target){
                return true;
            }
            if(sampleSpace[mid]>target){
                end=mid-1;
            }else{
                start = mid+1;
            }
        }
        return false;
    }
    
    vector<int> helper(vector<vector<int>> matrix,int target){
        int start = 0;
        int end = matrix.size()-1;
        while(end>=start){
            int mid = (start+end)/2;
            if(matrix[mid][0]==target){
                end = mid;
                break;
            }
            if(matrix[mid][0]>target){
                end = mid-1;
            }else{
                start = mid+1;
            }
        }
        if(end>= matrix.size() || start<0 ){
            return matrix[0];
        }
        return matrix[end];
    }
};