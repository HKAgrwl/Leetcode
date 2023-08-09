class Solution {
public:
    int snakesAndLadders(vector<vector<int>>& board) {
        int n = board.size();
        int square;
        int moves;
        queue<pair<int,int>> q;
        unordered_map<int,int> visited;
        q.push(make_pair(1,0));
        while(!q.empty()){
            square = (q.front()).first;
            moves = (q.front()).second;
            q.pop();
            // cout<<square<<" "<<moves<<endl;
            for(int i=1;i<=6;i++){
                int nextSquare =square + i;
                pair<int,int> p = getIndex(n,nextSquare);
                int row = p.first;
                int col = p.second;
                if(row>=n || col >=n || row<0 || col<0) continue;
                // cout<<row<<" "<<col<<endl;
                if(board[row][col]!=-1){
                    nextSquare = board[row][col];
                    // cout<<nextSquare<<endl;
                }
                if(nextSquare == n*n) return moves+1;
                if(!visited[nextSquare]){
                    visited[nextSquare] = 1;
                    q.push(make_pair(nextSquare,moves+1));
                    // cout<<nextSquare<<endl;
                }
            }
        }
        return -1;
    }
    
    pair<int,int> getIndex(int n, int val){
        int row = n-((val-1)/n)-1;
        int col = (val-1)%n;
        if((row%2==0 && n%2==0) || (n%2 && row%2)){
            col = n - col -1;
        }
        pair<int,int> p(row,col);
        return p;
    }
};