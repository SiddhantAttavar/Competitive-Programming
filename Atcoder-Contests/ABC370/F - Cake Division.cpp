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

int check(vector<int> &a, int m, int k) {
	int l = 0, x = a[0], n = a.size();
	while (l < n and x < m) {
		l++;
		x += a[l];
	}

	if (l == n) {
		return -1;
	}

	int j = 0;
	while (x - a[j] >= m) {
		x -= a[j];
		j++;
	}

	vector<vector<int>> p(n, vector<int>(20, -2));
	p[l][0] = j - 1;
	range(i, l + 1, n) {
		x += a[i];
		while (x - a[j] >= m) {
			x -= a[j];
			j++;
		}

		p[i][0] = j - 1;
		range(u, 1, 20) {
			if (p[i][u - 1] >= 0) {
				p[i][u] = p[p[i][u - 1]][u - 1];
			}
		}
	}

	vector<int> pref(n + 1, 0);
	range(i, 0, n) {
		pref[i + 1] = pref[i] + a[i];
	}

	bool flag = false;
	range(i, 0, n) {
		int u = i;
		bool b = true;
		for (int j = 19; j >= 0; j--) {
			if ((k - 1) & (1 << j)) {
				if (u < 0) {
					b = false;
					break;
				}
				u = p[u][j];
			}
		}

		if (!b or u == -2) {
			continue;
		}

		if (pref[u + 1] + pref[n] - pref[i + 1] >= m) {
			flag = true;
			break;
		}
	}

	if (!flag) {
		return -1;
	}

	int res = 0, z = 0;
	range(i, 0, n) {
		int u = i;
		for (int j = 19; j >= 0; j--) {
			if (z & (1 << j)) {
				u = p[u][j];
			}
		}

		if (u != -1 and p[u][0] != -2) {
			z++;
			u = p[u][0];
		}

		if (z >= k) {
			res++;
			continue;
		}

		int v = upper_bound(pref.begin(), pref.end(), pref[n] - (m - pref[u + 1])) - pref.begin() - 2;
		for (int j = 19; j >= 0; j--) {
			if ((k - z - 1) & (1 << j)) {
				if (v < 0) {
					break;
				}
				v = p[v][j];
			}
		}

		res += v >= i;
	}

	return n - res;
}

int32_t main() {
	setup();

	int n, k;
	input(n, k);

	vector<int> a(n);
	arrPut(a);

	int l = 1, r = 2e9;
	pair<int, int> res = {0, 0};
	while (l <= r) {
		int m = (l + r) / 2;
		int x = check(a, m, k);
		if (x != -1) {
			l = m + 1;
			res = {m, x};
		}
		else {
			r = m - 1;
		}
	}
	print(res.first, res.second);
}
