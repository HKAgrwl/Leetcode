class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> answer;
        if(matrix.size()==0) return answer;
        
        int rowBegin=0;
        int rowEnd= matrix.size()-1;
        int columnBegin = 0;
        int columnEnd = matrix[0].size()-1;
        
        while(rowBegin<=rowEnd && columnBegin<=columnEnd){
            for(int i=columnBegin ; i<=columnEnd;i++){
                answer.push_back(matrix[rowBegin][i]);
            }
            rowBegin++;
            for(int i=rowBegin; i<=rowEnd;i++){
                answer.push_back(matrix[i][columnEnd]);
            }
            columnEnd--;
            
            if(rowBegin<= rowEnd){
                for(int i=columnEnd;i>= columnBegin; i--){
                    answer.push_back(matrix[rowEnd][i]);
                }
            }
            rowEnd--;
            
            if(columnBegin<=columnEnd){
                for(int i=rowEnd;i>=rowBegin;i--){
                    answer.push_back(matrix[i][columnBegin]);
                }
            }
            columnBegin++;
        }
        
        return answer;
    }
};