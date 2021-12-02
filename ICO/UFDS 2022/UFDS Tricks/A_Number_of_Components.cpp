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

// Stores the parent of each vertex
int parent[1000000];
 
// Function to find the topmost
// parent of vertex a
int root(int a)
{
    // If current vertex is
    // the topmost vertex
    if (a == parent[a]) {
        return a;
    }
 
    // Otherwise, set topmost vertex of
    // its parent as its topmost vertex
    return parent[a] = root(parent[a]);
}
 
// Function to connect the component
// having vertex a with the component
// having vertex b
void connect(int a, int b)
{
    // Connect edges
    a = root(a);
    b = root(b);
 
    if (a != b) {
        parent[b] = a;
    }
}
 
// Function to find unique top most parents
void connectedComponents(int n)
{
    set<int> s;
 
    // Traverse all vertices
    for (int i = 0; i < n; i++) {
 
        // Insert all topmost
        // vertices obtained
        s.insert(root(parent[i]));
    }
 
    // Print count of connected components
    cout << s.size() << '\n';
}
 
// Function to print answer
void printAnswer(int N,
                 vector<vector<int> > edges)
{
 
    // Setting parent to itself
    for (int i = 0; i <= N; i++) {
        parent[i] = i;
    }
 
    // Traverse all edges
    for (int i = 0; i < edges.size(); i++) {
        connect(edges[i][0], edges[i][1]);
    	connectedComponents(N);
    }
 
    // Print answer
}

int32_t main() {
	setup();
	int n, m; input(n, m);
	vector<vector<int> > edges(m);
	for (int i = 0; i < m; i++) {
		int a, b; input(a, b);
		edges[i] = {a, b};
	}
	printAnswer(n, edges);
}
