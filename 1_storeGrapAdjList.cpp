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

// Space complexity of this approch is O(2*m) for undirected graph
// And for it will be O(E)
int main()
{
    int n, m;
    cin >> n >> m;
    vector<int> adj[n + 1];
    // Undirected list
    for (int i = 0; i < m; i++)
    {
        int v, u;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    // Directed list
    // for (int i = 0; i < m; i++)
    // {
    //     int v, u;
    //     cin >> u >> v;
    //     // There only be edge from u --> v
    //     adj[u].push_back(v);
    // }
    for (int i = 0; i <= n; i++)
    {
        cout << "Adjacent nodes of " << i << " are: ";
        for (auto j : adj[i])
        {
            cout << j << " ";
        }
        cout << endl;
    }

    return 0;
}
/*
5 6
1 2
1 3
3 4
2 4
2 5
4 5
*/