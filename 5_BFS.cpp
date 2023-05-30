/*
https://practice.geeksforgeeks.org/problems/bfs-traversal-of-graph/1
*/

class Solution {
  public:
    // Function to return Breadth First Traversal of given graph.
    vector<int> bfsOfGraph(int V, vector<int> adj[]) {
        // Code here
        queue<int> q;
        vector<int> vis(V,0);
        vector<int> bfs;
        q.push(0);
        vis[0] = 1;
        while(!q.empty()){
            int node = q.front();
            q.pop();
            bfs.push_back(node);
            
            for(auto i:adj[node]){
                if(!vis[i]){
                    vis[i] = 1;
                    q.push(i);
                }
            }
        }
        return bfs;
    }
};