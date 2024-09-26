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

struct DSU {
	vector<int> e; vector<pair<bool, bool>> p; DSU(int N) { e = vector<int>(N,-1); p = vector<pair<bool, bool>>(N, {false, false}); }
	int get(int x) { return e[x] < 0 ? x : e[x] = get(e[x]); } 
	bool sameSet(int a, int b) { return get(a) == get(b); }
	int size(int x) { return -e[get(x)]; }
	bool unite(int x, int y) {
		x = get(x), y = get(y); if (x == y) return 0;
		if (e[x] % 2) swap(p[y].first, p[y].second);
		p[x].first |= p[y].first;
		p[x].second |= p[y].second;
		e[x] += e[y]; e[y] = x; return 1;
	}
};

int32_t main() {
	setup(); int tc; input(tc); while (tc--) {
		int n;
		input(n);
		
		vector<int> a(n);
		arrPut(a);

		map<int, vector<int>> b;
		range(i, 0, n) {
			b[-a[i]].push_back(i);
		}

		DSU d(n);
		int x = *max_element(a.begin(), a.end());
		for (int i : b[-x]) {
			d.p[i].first = true;
		}

		int res = 0, c = 0, z = 0;
		for (pair<int, vector<int>> p : b) {
			for (int j : p.second) {
				bool u, v;
				if (j and a[j - 1] >= a[j]) {
					int k = d.size(j - 1);
					tie(u, v) = d.p[d.get(j - 1)];
					c -= (k + 1) / 2;
					z -= u or (v and k % 2 == 0);
					d.unite(j - 1, j);
				}

				if (j < n - 1 and a[j + 1] > a[j]) {
					int k = d.size(j + 1);
					tie(u, v) = d.p[d.get(j + 1)];
					c -= (k + 1) / 2;
					z -= u or (v and k % 2 == 0);
					d.unite(j, j + 1);
				}

				int k = d.size(j);
				tie(u, v) = d.p[d.get(j)];
				c += (k + 1) / 2;
				z += u or (v and k % 2 == 0);
			}

			res = max(res, x - p.first + c - (z == 0));
		}
		print(res);
	}
}
