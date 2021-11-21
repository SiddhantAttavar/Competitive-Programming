#include <bits/stdc++.h>
using namespace std;
template<typename T> inline void input(T& inVar) {cin >> inVar;}
template<typename T, typename... S> inline void input(T& inVar, S&... args) {cin >> inVar; input(args ...);}
template<typename T> inline void print(T outVar) {cout << outVar << endl;}
template<typename T, typename... S> inline void print(T outVar, S... args) {cout << outVar << ' '; print(args ...);}
#define range(it, start, end) for (int it = start; it < end; it++)
#define arrPut(var) for (auto &inVar : var) {cin >> inVar;}
#define arrPrint(var) for (auto outVar : var) {cout << outVar << ' ';} cout << endl
#define setup() ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define int long long

bool possible = false;
vector<int> ans;
int n;

class Graph
{
    int V;    // No. of vertices
 
    // Pointer to an array containing adjacency list
    list<int> *adj;
 
    // Vector to store indegree of vertices
    vector<int> indegree;
 
    // A function used by alltopologicalSort
    void alltopologicalSortUtil(vector<int>& res,
                                bool visited[]);
 
public:
    Graph(int V);   // Constructor
 
    // function to add an edge to graph
    void addEdge(int v, int w);
 
    // Prints all Topological Sorts
    void alltopologicalSort();

	void solve(vector<int>& res);
};

void Graph::solve(vector<int> &res) {
	arrPrint(res);
	vector<int> ind(n);
	range(i, 0, n) {
		ind[res[i]] = i;
	}
	for (int i : res) {
		for (int j : adj[i]) {
			if (i == j) continue;
			if (ind[i] > ind[j]) {
				if (ind[i] - ind[j] <= ceil(n / 2.0)) {
					return;
				}
			}
		}
	}
	possible = true;
	ans = res;
}
 
//  Constructor of graph
Graph::Graph(int V)
{
    this->V = V;
    adj = new list<int>[V];
 
    // Initialising all indegree with 0
    for (int i = 0; i < V; i++)
        indegree.push_back(0);
}
 
//  Utility function to add edge
void Graph::addEdge(int v, int w)
{
    adj[v].push_back(w); // Add w to v's list.
 
    // increasing inner degree of w by 1
    indegree[w]++;
}
 
//  Main recursive function to print all possible
//  topological sorts
void Graph::alltopologicalSortUtil(vector<int>& res,
                                   bool visited[])
{
    // To indicate whether all topological are found
    // or not
    bool flag = false;
 
    for (int i = 0; i < V; i++)
    {
        //  If indegree is 0 and not yet visited then
        //  only choose that vertex
        if (indegree[i] == 0 && !visited[i])
        {
            //  reducing indegree of adjacent vertices
            list<int>:: iterator j;
            for (j = adj[i].begin(); j != adj[i].end(); j++)
                indegree[*j]--;
 
            //  including in result
            res.push_back(i);
            visited[i] = true;
            alltopologicalSortUtil(res, visited);
 
            // resetting visited, res and indegree for
            // backtracking
            visited[i] = false;
            res.erase(res.end() - 1);
            for (j = adj[i].begin(); j != adj[i].end(); j++)
                indegree[*j]++;
 
            flag = true;
        }
    }
 
    //  We reach here if all vertices are visited.
    //  So we print the solution here
    if (!flag)
    {
		print("Debug");
		solve(res);
    }
}
 
//  The function does all Topological Sort.
//  It uses recursive alltopologicalSortUtil()
void Graph::alltopologicalSort()
{
    // Mark all the vertices as not visited
    bool *visited = new bool[V];
    for (int i = 0; i < V; i++)
        visited[i] = false;
 
    vector<int> res;
    alltopologicalSortUtil(res, visited);
}

int32_t main() {
	setup(); int tc; input(tc); while (tc--) {
		input(n);
		Graph graph(n);
		possible = false;
		ans = vector<int>(n);
		range(i, 0, n) {
			string s; input(s);
			range(j, 0, n) {
				if (s[j] == '1') {
					graph.addEdge(i, j);
				}
			}
		}
		graph.alltopologicalSort();
		if (!possible) {
			print(-1);
		}
		else {
			range(i, 0, n) {
				ans[i]++;
			}
			arrPrint(ans);
		}
	}
}
