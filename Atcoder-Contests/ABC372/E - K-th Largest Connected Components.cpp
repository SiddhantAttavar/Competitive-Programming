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
#define range(it, start, end) for (auto it = start; it < end; it++)
#define arrPut(var) for (auto &inVar : var) {cin >> inVar;}
#define arrPrint(var) for (auto outVar : var) {cout << outVar << ' ';} cout << '\n'
#define setup() ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define ordered_set tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> 
const int MOD = (int) 1e9 + 7; //998244353

vector<int> merge(vector<int> a, vector<int> b) {
	int i = 0, j = 0;
	vector<int> res;
	while ((i < a.size() or j < b.size()) and res.size() < 10) {
		if ((i == a.size()) or (j < b.size() and b[j] > a[i])) {
			res.push_back(b[j]);
			j++;
		}
		else {
			res.push_back(a[i]);
			i++;
		}
	}
	return res;
}

struct DSU {
	vector<int> e;
	vector<vector<int>> a;
	void init(int N) { e = vector<int>(N,-1); a = vector<vector<int>>(N); range(i, 0, N) {a[i] = {i};} }
	int get(int x) { return e[x] < 0 ? x : e[x] = get(e[x]); } 
	bool sameSet(int a, int b) { return get(a) == get(b); }
	int size(int x) { return -e[get(x)]; }
	bool unite(int x, int y) { // union by size
		x = get(x), y = get(y); if (x == y) return 0;
		if (e[x] > e[y]) swap(x,y);
		a[x] = merge(a[x], a[y]);
		e[x] += e[y];
		e[y] = x;
		return 1;
	}
};

int32_t main() {
	setup();

	int n, q;
	input(n, q);

	DSU d;
	d.init(n);

	while (q--) {
		int o;
		input(o);

		if (o == 1) {
			int u, v;
			input(u, v);
			d.unite(u - 1, v - 1);
		}
		else {
			int v, k;
			input(v, k);
			v = d.get(v - 1);
			if (d.a[v].size() >= k) {
				print(d.a[v][k - 1] + 1);
			}
			else {
				print(-1);
			}
		}
	}
}
