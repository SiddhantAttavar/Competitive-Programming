#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp> 
#include <ext/pb_ds/tree_policy.hpp> 
using namespace std;
using namespace __gnu_pbds; 
template<typename T> inline void input(T& inVar) {cin >> inVar;}
template<typename T, typename... S> inline void input(T& inVar, S&... args) {cin >> inVar; input(args ...);}
template<typename T> inline void print(T outVar) {cout << outVar << '\n';}
template<typename T, typename... S> inline void print(T outVar, S... args) {cout << outVar << ' '; print(args ...);}
#define int long long
#define rep(it, start, end) for (auto it = start; it < end; it++)
#define arrput(var) for (auto &inVar : var) {cin >> inVar;}
#define arrprint(var) for (auto outVar : var) {cout << outVar << ' ';} cout << '\n'
#define setup() ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define ordered_set tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> 
const int MOD = (int) 1e9 + 7; //998244353;

#define vi vector<int>
vector<vi> decomp;
vector<vi> adj; vi siz;
vector<bool> vis;
void find_size(int v, int p) {
	siz[v] = 1;
	for(auto nx : adj[v]) if(nx != p && !vis[nx]) {
		find_size(nx, v);
		siz[v] += siz[nx];
	}
}
int centroid(int v, int p, int n) {
	for(auto nx : adj[v]) if(nx != p && !vis[nx] && siz[nx] > n/2) {
		return centroid(nx, v, n);
	}
	return v;
}
void process(int v) {}
int solve(int v, int p) {
	find_size(v, p);
	int c = centroid(v, p, siz[v]);
	process(c);
	vis[c] = true;
	for(auto nx : adj[c]) if(!vis[nx]) decomp[c].push_back(solve(nx, c));
	return c;
}

int32_t main() {
	setup(); int tc; input(tc); while (tc--) {
		
	}
}
