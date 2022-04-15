class Solution {
    public boolean exist(char[][] board, String word) {
        int nrow = board.length;
        int ncol = board[0].length;
        int l = word.length();
        if(l>nrow*ncol){
            return false;
        }
        for(int i=0;i<nrow;i++){
            for(int j=0;j<ncol;j++){
                if(board[i][j]==word.charAt(0)){
                    if(findMatch(board,word,i,j,nrow,ncol,0)){
                        return true;
                    }
                }
            }
        }
        return false;
    }
    
    static boolean findMatch(char[][] mat,String word, int x, int y,int nrow,int ncol,int level){
        int l = word.length();
        if (level == l){
            return true;
        }
        // Out of Boundary
        if (x < 0 || y < 0 || x >= nrow || y >= ncol){
            return false;
        }
        if (mat[x][y] == word.charAt(level)){
            char temp = mat[x][y];
            mat[x][y] = '#';
            boolean res = findMatch(mat, word, x - 1, y, nrow, ncol, level + 1) |
                    findMatch(mat, word, x + 1, y, nrow, ncol, level + 1) |
                    findMatch(mat, word, x, y - 1, nrow, ncol, level + 1) |
                    findMatch(mat, word, x, y + 1, nrow, ncol, level + 1);
            mat[x][y] = temp;
            return res;
        }else{
            return false;
        }
    }
}