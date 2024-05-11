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
const int MOD = (int) 1e9 + 7;

struct DSU {
	vector<int> a;

	DSU(int n) {
		a.resize(n, -1);
	}

	int get(int x) {
		if (a[x] < 0) {
			return x;
		}
		return a[x] = get(a[x]);
	}

	bool unite(int x, int y) {
		x = get(x);
		y = get(y);

		if (x == y) {
			return false;
		}

		if (a[x] < a[y]) {
			swap(x, y);
		}

		a[x] += a[y];
		a[y] = x;
		return true;
	}
};

int32_t main() {
	setup();

	int n, m;
	input(n, m);

	vector<pair<int, vector<int>>> a(m);
	range(i, 0, m) {
		int k;
		input(k, a[i].first);
		a[i].second.resize(k);
		arrPut(a[i].second);
	}
	sort(a.begin(), a.end());

	int res = 0, s = n;
	DSU d(n);
	for (pair<int, vector<int>> p : a) {
		for (int i : p.second) {
			if (d.unite(i, p.second[0])) {
				res += p.first;
				s--;
			}
		}
	}

	if (s == 1) {
		print(res);
	}
	else {
		print(-1);
	}
}
