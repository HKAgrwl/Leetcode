class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int n = matrix.size();
        int m = matrix[0].size();
        vector<int> rows;
        vector<int> columns;
        for(int i=0;i<n;i++){
            if(matrix[i][0] < target && matrix[i][m-1] > target) rows.push_back(i);
            if(matrix[i][0]==target) return true;
            if(matrix[i][m-1]==target) return true;
        }
        for(int i=0;i<m;i++){
            if(matrix[0][i] < target && matrix[n-1][i] > target) columns.push_back(i);
            if(matrix[0][i]==target) return true;
            if(matrix[n-1][i]==target) return true;
        }
        for(auto x : rows){
            for(auto y :columns){
                if(matrix[x][y]==target) return true;
            }
        }
        return false;
    }
};