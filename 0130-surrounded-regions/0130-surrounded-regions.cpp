class Solution {
public:
    void dfs(int r, int c, vector<vector<int>>& vis, vector<vector<char>> board, int n, int m){
        vis[r][c]=1;

        int drow[]={-1, 0, 1, 0};
        int dcol[]={0, -1, 0, 1};

        for(int i=0;i<4;i++){
            int nr = r + drow[i];
            int nc = c + dcol[i];

            if(nr >= 0 and nr < n and nc >= 0 and nc < m and !vis[nr][nc] and board[nr][nc]=='O'){
                dfs(nr, nc, vis, board, n, m);
            }
        }
    }
    void solve(vector<vector<char>>& board) {
        int n=board.size();
        int m=board[0].size();
        vector<vector<int>> vis(n, vector(m, 0));

        for(int j=0;j<m;j++){
            if(!vis[0][j] and board[0][j]=='O'){
               dfs(0, j, vis, board, n, m);

            }
            if(!vis[n-1][j] and board[n-1][j] == 'O'){
               dfs(n-1, j, vis, board, n, m);
            }
            
        }

        for(int i=0;i<n;i++){
            if(!vis[i][0] and board[i][0] == 'O'){
                dfs(i, 0, vis, board, n, m);
            }
             if(!vis[i][m-1] and board[i][m-1] == 'O'){
                dfs(i, m-1, vis, board, n, m);
            }
        }
        
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(!vis[i][j] and board[i][j]=='O')
                board[i][j]='X';
            }
        }
       
        
        
    }
};