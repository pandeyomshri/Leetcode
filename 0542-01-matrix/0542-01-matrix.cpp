class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int n = mat.size();
        int m = mat[0].size();
        vector<vector<int>> v(n , vector<int>(m,0));
        vector<vector<int>> distance(n , vector<int>(m,0));

        queue<pair<pair<int,int> , int>> q;
        for(int i = 0;i<n;i++){
            for(int j = 0 ;j<m;j++){
                if(mat[i][j] == 0){
                    v[i][j] =1;
                    q.push({{i,j},0});
                }
                else{
                    v[i][j] = 0;
                }
            
            }
        }
        int delrow[] = { +1 , 0 , -1 , 0};
        int delcol[] = {0 , -1 , 0 , +1};
        while(!q.empty()){
            int r = q.front().first.first;
            int c = q.front().first.second;
            int dis = q.front().second;
            q.pop();
            distance[r][c] = dis;
            for(int i = 0;i<4;i++){
                int nrow = delrow[i]+r;
                int ncol = delcol[i]+c;

                if(nrow < n && nrow>= 0 && ncol < m && ncol >= 0 && v[nrow][ncol] ==0){
                    v[nrow][ncol]  = 1;
                    q.push({{nrow, ncol} , dis+1});
                }
            }
        }

        return distance;
    }
};