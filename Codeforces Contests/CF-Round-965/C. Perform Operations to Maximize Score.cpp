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

bool check(int m, vector<pair<int, int>> &v, int k) {
	int n = v.size();
	int x = n / 2 + 1;
	for (int i = n - 1; i >= 0; i--) {
		if (!v[i].second and v[i].first >= m) {
			x--;
		}
	}
	if (x <= 0) {
		return true;
	}

	int res = 0;
	for (int i = n - 1; i >= 0; i--) {
		if (!v[i].second) {
			continue;
		}

		res += max(0ll, m - v[i].first);
		x--;
		if (res > k) {
			return false;
		}
		if (x == 0) {
			return true;
		}
	}
	return false;
}

int32_t main() {
	setup(); int tc; input(tc); while (tc--) {
		int n, k;
		input(n, k);

		vector<int> a(n), b(n);
		arrPut(a);
		arrPut(b);

		vector<pair<int, int>> p;
		int u = -1;
		range(i, 0, n) {
			if (b[i]) {
				p.push_back({a[i], i});
			}
			else if (u == -1 or a[u] < a[i]) {
				u = i;
			}
		}
		sort(p.begin(), p.end());

		int res = 0;
		if (p.size()) {
			vector<int> v(a);
			v.erase(v.begin() + p.back().second);
			sort(v.begin(), v.end());
			res = p.back().first + k + v[n / 2 - 1];
		}

		if (u == -1) {
			print(res);
			continue;
		}

		vector<pair<int, int>> v(n);
		range(i, 0, n) {
			v[i] = {a[i], b[i]};
		}
		v.erase(v.begin() + u);
		sort(v.begin(), v.end());

		int l = max(res, a[u]), r = 1e9;
		while (l <= r) {
			int m = (l + r) / 2;
			if (check(m - a[u], v, k)) {
				res = m;
				l = m + 1;
			}
			else {
				r = m - 1;
			}
		}
		print(res);
	}
}
