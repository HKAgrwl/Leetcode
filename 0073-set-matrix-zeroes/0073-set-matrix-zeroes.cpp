class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        vector<vector<int>> v;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(matrix[i][j] == 0){
                    vector<int> temp = {i,j};
                    v.push_back(temp);
                }
            }
        }
        for(auto x : v){
            for(int t=0;t<m;t++) matrix[t][x[1]] = 0;
            for(int p=0;p<n;p++) matrix[x[0]][p] = 0;
        }
    }
};