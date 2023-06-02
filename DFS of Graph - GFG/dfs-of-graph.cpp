//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    void dfs(int V, int * vis, vector <int> &ans, vector <int> adj[], int startNode){
        if (vis[startNode]) 
            return;
            
        ans.push_back(startNode);
        vis[startNode] = 1;
        
        for(int i : adj[startNode]){
            if ( !vis[i] )
                dfs(V, vis, ans, adj, i);
        }
    }
    // Function to return a list containing the DFS traversal of the graph.
    vector<int> dfsOfGraph(int V, vector<int> adj[]) {
        // Code here
        int * vis = (int *)calloc(sizeof(int), V);
        
        vector <int> ans;
        
        dfs(V, vis, ans, adj, 0);
        
        return ans;
    }
};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int V, E;
        cin >> V >> E;

        vector<int> adj[V];

        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        // string s1;
        // cin>>s1;
        Solution obj;
        vector<int> ans = obj.dfsOfGraph(V, adj);
        for (int i = 0; i < ans.size(); i++) {
            cout << ans[i] << " ";
        }
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends