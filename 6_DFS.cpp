/*https://practice.geeksforgeeks.org/problems/depth-first-traversal-for-a-graph/1*/

class Solution {
    private:
    
    void dfs(int node, vector<int> adj[], vector<int> &vis,vector<int> &ans){
        vis[node] = 1;
        ans.push_back(node);
        for(auto i:adj[node]){
            if(vis[i] != 1){
                dfs(i,adj,vis,ans);
            }
        }
    }
    
  public:
    // Function to return a list containing the DFS traversal of the graph.
    vector<int> dfsOfGraph(int V, vector<int> adj[]) {
        // Code here
        vector<int> ans;
        vector<int> vis(V,0);
        int start = 0;
    }
        dfs(start,adj,vis,ans);
        return ans;
};