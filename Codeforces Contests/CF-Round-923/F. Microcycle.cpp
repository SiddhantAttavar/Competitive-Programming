#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp> 
#include <ext/pb_ds/tree_policy.hpp> 
using namespace std;
using namespace __gnu_pbds; 
template<typename T> inline void input(T& inVar) {cin >> inVar;}
template<typename T, typename... S> inline void input(T& inVar, S&... args) {cin >> inVar; input(args ...);}
template<typename T> inline void print(T outVar) {cout << outVar << '\n';}
template<typename T, typename... S> inline void print(T outVar, S... args) {cout << outVar << ' '; print(args ...);}
#define range(it, start, end) for (auto it = start; it < end; it++)
#define arrPut(var) for (auto &inVar : var) {cin >> inVar;}
#define arrPrint(var) for (auto outVar : var) {cout << outVar << ' ';} cout << '\n'
#define setup() ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define int long long
#define ordered_set tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> 
const int MOD = (int) 1e9 + 7;
const int N = 100000;
 
// variables to be used
// in both functions
vector<int> graph[N];
vector<vector<int>> cycles;
 
// Function to mark the vertex with
// different colors for different cycles
void dfs_cycle(int u, int p, int color[], int par[], int& cyclenumber)
{
 
    // already (completely) visited vertex.
    if (color[u] == 2) {
        return;
    }
 
    // seen vertex, but was not completely visited -> cycle detected.
    // backtrack based on parents to find the complete cycle.
    if (color[u] == 1) {
        vector<int> v;
        cyclenumber++;
           
        int cur = p;
          v.push_back(cur);
 
        // backtrack the vertex which are
        // in the current cycle thats found
        while (cur != u) {
            cur = par[cur];
              v.push_back(cur);
        }
          cycles.push_back(v);
        return;
    }
    par[u] = p;
 
    // partially visited.
    color[u] = 1;
 
    // simple dfs on graph
    for (int v : graph[u]) {
 
        // if it has not been visited previously
        if (v == par[u]) {
            continue;
        }
        dfs_cycle(v, u, color, par, cyclenumber);
    }
 
    // completely visited.
    color[u] = 2;
}
 
// add the edges to the graph
void addEdge(int u, int v)
{
    graph[u].push_back(v);
    graph[v].push_back(u);
}

int b, k;
vector<int> res;
vector<map<int, int>> adj;
 
// Function to print the cycles
void printCycles(int& cyclenumber)
{
 
    // print all the vertex with same cycle
	print("");
	print(cyclenumber);
    for (int i = 0; i < cyclenumber; i++) {
		int c = adj[cycles[i][0]][cycles[i].back()], p = cycles[i][0];
		range(j, 1, cycles[i].size()) {
			c = min(c, adj[p][cycles[i][j]]);
			p = cycles[i][j];
			// print(j, c);
		}
		if (c < b) {
			b = c;
			k = cycles[i].size();
		}
		res = cycles[i];
		range(i, 0, res.size()) {
			res[i]++;
		}
        // Print the i-th cycle
        // cout << "Cycle Number " << i + 1 << ": ";
        // for (int x : cycles[i])
        //     cout << x << " ";
        // cout << endl;
    }
}

//
// int dfs(int u, vector<vector<pair<int, int>>> &graph, vector<bool> &vis, vector<bool> &in_stack, int m) {
// 	vis[u] = true;
// 	in_stack[u] = true;
// 	int res = 1e9;
// 	for (pair<int, int> p : graph[u]) {
// 		if (!vis[p.first]) {
// 			res = min(res, dfs(p.first, graph, vis, in_stack, min(m, p.second)));
// 		}
// 		else if (in_stack[p.first]) {
// 			res = min({m, p.second});
// 		}
// 	}
// 	in_stack[u] = false;
// 	return res;
// }
int color[N];
int par[N];

int32_t main() {
	setup(); int tc; input(tc); while (tc--) {
		int n, m;
		input(n, m);

		adj.clear();
		adj.resize(n);
		b = 1e9;
		cycles.clear();
		fill(graph, graph + n, vector<int>());

		range(i, 0, m) {
			int u, v, w;
			input(u, v, w);

			// graph[u - 1].push_back({v - 1, w});
			// graph[v - 1].push_back({u - 1, w});
			addEdge(u - 1, v - 1);
			adj[u - 1][v - 1] = w;
			adj[v - 1][u - 1] = w;
		}

		// vector<bool> vis(n, false), in_stack(n, false);
		// int res = 1e9;
		// range(i, 0, n) {
		// 	if (!vis[i]) {
		// 		res = min(res, dfs(i, graph, vis, in_stack, 1e9));
		// 	}
		// }
		
		int cycleNumber = 0;
		dfs_cycle(1, 0, color, par, cycleNumber);

		printCycles(cycleNumber);

		print(b, k);
		arrPrint(res);
	}
}
