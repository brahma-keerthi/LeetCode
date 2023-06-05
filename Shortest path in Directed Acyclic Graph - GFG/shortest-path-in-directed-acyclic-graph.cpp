//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
class Solution {
  public:
    void dfs(int N, unordered_map <int, vector <vector <int>> > adj, stack <int> &topo, int * vis, int node ){
        vis[node] = 1;
        
        for(auto i : adj[node]){
            int a = i[0];
            if ( !vis[a] ){
                vis[a] = 1;
                dfs(N, adj, topo, vis, a) ;
            }
        }
        
        topo.push(node);
    }
    vector<int> shortestPath(int N,int M, vector<vector<int>>& edges){
        // code here
        unordered_map <int, vector <vector <int>> > adj;
        for(int i = 0; i<M; ++i){
            vector <int> sub;
            sub.push_back(edges[i][1]);
            sub.push_back(edges[i][2]);
            adj[edges[i][0]].push_back(sub);
        }
        
        stack <int> topo;
        int * vis = (int *)calloc(sizeof(int), N);
        
        for(int i = 0; i<N; ++i)
            if ( !vis[i] )
                dfs(N,adj, topo, vis, i);
                
        vector <int> dis(N, INT_MAX);
        
        dis[0] = 0;
        
        while ( !topo.empty() ){
            int top = topo.top();
            topo.pop();
            
            if ( dis[top] != INT_MAX ){
                for(auto i : adj[top] ){
                    if ( dis[top] + i[1] < dis[i[0]] )
                        dis[i[0]] = dis[top] + i[1];
                }
            }
        }
        
        for(int i = 0; i<N; ++i)
            if ( dis[i] == INT_MAX)
                dis[i] = -1;
                
        return dis;
        
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> edges;
        for(int i=0; i<m; ++i){
            vector<int> temp;
            for(int j=0; j<3; ++j){
                int x; cin>>x;
                temp.push_back(x);
            }
            edges.push_back(temp);
        }
        Solution obj;
        vector<int> res = obj.shortestPath(n, m, edges);
        for (auto x : res) {
            cout << x << " ";
        }
        cout << "\n";
    }
}

// } Driver Code Ends