//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
public:
    bool forComponents(int start, int n, vector<int>graph[], vector<int>& color){
        queue<int> q;
        q.push(start);
        
        color[start]=0;
        
        while(!q.empty()){
            int node = q.front();
            q.pop();

            for(int i=0;i<graph[node].size();i++){

                if(color[graph[node][i]]==-1){
                    color[graph[node][i]]=!color[node];
                    q.push(graph[node][i]);
                }
                else{
                    if( color[graph[node][i]] == color[node])
                    return false;
                }
            }

        }
        return true;
    }
	bool isBipartite(int n, vector<int>graph[]){
	    
	  vector<int> color(n, -1);
	  for(int i=0;i<n;i++){
	      if(color[i]==-1){
	          if(forComponents(i, n, graph, color)==false)
	          return false;
	      }
	  }
        return true;
	    // Code here
	}

};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int V, E;
		cin >> V >> E;
		vector<int>adj[V];
		for(int i = 0; i < E; i++){
			int u, v;
			cin >> u >> v;
			adj[u].push_back(v);
			adj[v].push_back(u);
		}
		Solution obj;
		bool ans = obj.isBipartite(V, adj);    
		if(ans)cout << "1\n";
		else cout << "0\n";  
	}
	return 0;
}
// } Driver Code Ends