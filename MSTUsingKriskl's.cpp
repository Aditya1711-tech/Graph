#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <bitset>
#include <complex>
#include <deque>
#include <exception>
#include <fstream>
#include <functional>
#include <iomanip>
#include <ios>
#include <iosfwd>
#include <iostream>
#include <istream>
#include <iterator>
#include <limits>
#include <list>
#include <locale>
#include <map>
#include <memory>
#include <new>
#include <numeric>
#include <ostream>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <stdexcept>
#include <streambuf>
#include <string>
#include <typeinfo>
#include <utility>
#include <valarray>
#include <vector>
#define ll long long int
using namespace std;

class DisjointSet
{
    vector<int> rank, parent, size;

public:
    DisjointSet(int n)
    {
        rank.resize(n + 1, 0);
        parent.resize(n + 1, 0);
        size.resize(n + 1);
        for (int i = 0; i <= n; i++)
        {
            parent[i] = i;
            size[i] = 1;
        }
    }

    int findUParent(int node)
    {
        if (parent[node] == node)
            return node;
        return parent[node] = findUParent(parent[node]);
    }

    void unionByRank(int u, int v)
    {
        int ulp_u = findUParent(u);
        int ulp_v = findUParent(v);
        if (ulp_u == ulp_v)
            return;

        if (rank[ulp_u] < rank[ulp_v])
        {
            parent[ulp_u] = ulp_v;
        }
        else if (rank[ulp_v] < rank[ulp_u])
        {
            parent[ulp_v] = ulp_u;
        }
        else
        {
            parent[ulp_v] = ulp_u;
            rank[ulp_u]++;
        }
    }

    void unionBySize(int u, int v)
    {
        int ulp_u = findUParent(u);
        int ulp_v = findUParent(v);
        if (ulp_u == ulp_v)
            return;
        if (size[ulp_u] < size[ulp_v])
        {
            parent[ulp_u] = ulp_v;
            size[ulp_v] += size[ulp_u];
        }
        else
        {
            parent[ulp_v] = ulp_u;
            size[ulp_u] += size[ulp_v];
        }
    }
};

class Solution
{
public:
    // Function to find sum of weights of edges of the Minimum Spanning Tree.
    int spanningTree(int V, vector<vector<int> > adj[])
    {
        vector<pair<int, pair<int, int> > > edges;
        for (int i = 0; i < V; i++)
        {
            for (auto it : adj[i])
            {
                int adjNode = it[0];
                int wt = it[1];
                int node = i;
                edges.push_back(make_pair(wt, make_pair(node, adjNode)));
            }
        }
        DisjointSet ds(V);
        sort(edges.begin(), edges.end());
        int minCost = 0;

        for (auto it : edges)
        {
            int wt = it.first;
            int u = it.second.first;
            int v = it.second.second;

            if (ds.findUParent(u) != ds.findUParent(v))
            {
                minCost += wt;
                ds.unionBySize(u, v);
            }
        }
        return minCost;
    }
};

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int V, E;
        cin >> V >> E;
        vector<vector<int> > adj[V];
        int i = 0;
        while (i++ < E)
        {
            int u, v, w;
            cin >> u >> v >> w;
            vector<int> t1, t2;
            t1.push_back(v);
            t1.push_back(w);
            adj[u].push_back(t1);
            t2.push_back(u);
            t2.push_back(w);
            adj[v].push_back(t2);
        }

        Solution obj;
        cout << obj.spanningTree(V, adj) << "\n";
    }

    return 0;
}