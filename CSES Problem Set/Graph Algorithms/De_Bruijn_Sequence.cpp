#include <bits/stdc++.h>
#define range(it, start, end) for (int it = start; it < end; it++)
#define input(x) cin >> x
#define print(x) cout << x << endl
#define arrPut(var) for (auto &i : var) {cin >> i;}
#define arrPrint(var) for (auto outVar : var) {cout << outVar << " ";} cout << endl
#define setup() ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
using namespace std;
typedef long long ll;
const int MOD = 1e9 + 7;

unordered_set<string> seen; 
vector<int> edges; 
  
// Modified DFS in which no edge 
// is traversed twice 
void dfs(string node, int& k, string& A) 
{ 
    for (int i = 0; i < k; ++i) { 
        string str = node + A[i]; 
        if (seen.find(str) == seen.end()) { 
            seen.insert(str); 
            dfs(str.substr(1), k, A); 
            edges.push_back(i); 
        } 
    } 
} 
  
// Function to find a de Bruijn sequence 
// of order n on k characters 
string deBruijn(int n, int k, string A) 
{ 
  
    // Clearing global variables 
    seen.clear(); 
    edges.clear(); 
  
    string startingNode = string(n - 1, A[0]); 
    dfs(startingNode, k, A); 
  
    string S; 
  
    // Number of edges 
    int l = pow(k, n); 
    for (int i = 0; i < l; ++i) 
        S += A[edges[i]]; 
    S += startingNode; 
  
    return S; 
} 

int main() {
	setup();
	
	int n; input(n);
	print(deBruijn(n, 2, "01"));
}