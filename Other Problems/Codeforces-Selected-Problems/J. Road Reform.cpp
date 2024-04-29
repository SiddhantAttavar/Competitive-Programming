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

		if (a[x] > a[y]) {
			swap(x, y);
		}

		a[x] += a[y];
		a[y] = x;
		return true;
	}
};

int32_t main() {
	setup(); int tc; input(tc); while (tc--) {
		int n, m, k;
		input(n, m, k);

		vector<pair<int, pair<int, int>>> e(m);
		range(i, 0, m) {
			input(e[i].second.first, e[i].second.second, e[i].first);
			e[i].second.first--;
			e[i].second.second--;
		}
		sort(e.begin(), e.end());
		reverse(e.begin(), e.end());

		DSU d(n);
		int x = -1, y = 1e18;
		int s = n;
		for (pair<int, pair<int, int>> p : e) {
			if (p.first > k) {
				y = p.first;
				continue;
			}

			if (x == -1) {
				x = p.first;
			}

			if (d.unite(p.second.first, p.second.second)) {
				s--;
			}
		}

		if (s == 1) {
			print(min(k - x, y - k));
			continue;
		}

		int res = 1e18;
		y = 0;
		reverse(e.begin(), e.end());
		for (pair<int, pair<int, int>> p : e) {
			if (p.first <= k) {
				continue;
			}

			if (d.unite(p.second.first, p.second.second)) {
				y += p.first - k;
				s--;
			}
			if (s == 1) {
				res = min(res, y);
				break;
			}
		}

		print(res);
	}
}
