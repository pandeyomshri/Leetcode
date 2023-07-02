class Solution {
public:
    int numEnclaves(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();

        int drow[]={-1, 0, 1, 0};
        int dcol[]={0, -1, 0, 1};

        vector<vector<int>> vis(n, vector(m, 0));
        queue<pair<int,int>> q;

        for(int j=0;j<m;j++){
            if(grid[0][j]==1){
            q.push({0,j});
            vis[0][j]=1;
            }

            if(grid[n-1][j]==1){
            q.push({n-1, j});
            vis[n-1][j]=1;
            }
        }

        for(int i=0;i<n;i++){
            if(grid[i][0]==1){
            q.push({i, 0});
            vis[i][0]=1;
            }

            if(grid[i][m-1]==1){
            q.push({i, m-1});
            vis[i][m-1]=1;
            }
        }
         while(!q.empty()){
             int row=q.front().first;
             int col=q.front().second;
             q.pop();

             for(int i=0;i<4;i++){
                 int nrow = row + drow[i];
                 int ncol = col + dcol[i];
                 
                if(nrow >= 0 and nrow < n and ncol >= 0 and ncol < m and !vis[nrow][ncol] and grid[nrow][ncol]==1){
                    vis[nrow][ncol]=1;
                    q.push({nrow, ncol});
                }
             }
         }
         int ans=0;
         for(int i=0;i<n;i++){
             for(int j=0;j<m;j++){
                 if(grid[i][j]==1 and !vis[i][j])
                 ans++; 
             }
         }
         return ans;
        
    }
};