//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    // Function to detect cycle in a directed graph.
    bool dfs(int V, vector <int> adj[], int * vis, int * dfsVis, int node){
        vis[node] = 1;
        dfsVis[node] = 1;
        
        for(int i : adj[node] ){
            if ( vis[i] && dfsVis[i] )
                return true;
            else if ( !vis[i] ){
                if ( dfs(V, adj, vis, dfsVis, i ) )
                    return true;
            }
        }
        
        dfsVis[node] = 0;
        return false;
    }
    
    bool isCyclic(int V, vector<int> adj[]) {
        // code here
        int * vis = (int *)calloc(sizeof(int), V);
        int * dfsVis = (int *)calloc(sizeof(int), V);
        
        for(int i = 0; i<V; ++i){
            if ( !vis[i] && dfs(V, adj, vis, dfsVis, i) )
                return true;
        }
        
        return false;
    }
};

//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;

        vector<int> adj[V];

        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
        }

        Solution obj;
        cout << obj.isCyclic(V, adj) << "\n";
    }

    return 0;
}

// } Driver Code Ends