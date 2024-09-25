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

int range_gcd(int l, int r, vector<vector<int>> &pref) {
	int res = 0;
	for (int i = 19; i >= 0; i--) {
		if ((r - l + 1) >= (1 << i)) {
			res = __gcd(res, pref[r][i]);
			r -= 1 << i;
		}
	}
	return res;
}

int32_t main() {
	setup(); int tc; input(tc); while (tc--) {
		int n, o;
		input(n, o);

		vector<int> a(n);
		arrPut(a);

		vector<vector<int>> pref(n, vector<int>(20, -1));
		range(i, 0, n) {
			pref[i][0] = a[i];
			range(j, 1, 20) {
				if (i + 1 < (1 << j)) {
					break;
				}
				pref[i][j] = __gcd(pref[i][j - 1], pref[i - (1 << (j - 1))][j - 1]);
			}
		}

		int res = n + 1;
		range(i, 0, n) {
			vector<int> u;
			int j = i - 1;
			int x = 1e9;
			while (j >= 0) {
				int l = 0, r = j, c = -1;
				while (l <= r) {
					int m = (l + r) / 2;
					if (range_gcd(m, i - 1, pref) == x) {
						r = m - 1;
					}
					else {
						c = m;
						l = m + 1;
					}
				}

				if (c != -1) {
					u.push_back(c);
					x = range_gcd(c, i - 1, pref);
				}
				j = c - 1;
			}
			reverse(u.begin(), u.end());

			vector<int> v;
			j = i + 1;
			x = 1e9;
			while (j < n) {
				int l = j, r = n - 1, c = n;
				while (l <= r) {
					int m = (l + r) / 2;
					if (range_gcd(i + 1, m, pref) == x) {
						l = m + 1;
					}
					else {
						c = m;
						r = m - 1;
					}
				}

				if (c != n) {
					v.push_back(c);
					x = range_gcd(i + 1, c, pref);
				}
				j = c + 1;
			}

			int k = 0;
			while (k < u.size() and a[i] - range_gcd(u[k], i - 1, pref) >= o) {
				k++;
			}
			if (k and a[i] - range_gcd(u[k - 1], i - 1, pref) >= 0) {
				res = min(res, i - u[k - 1] + 1);
			}

			range(j, 0, v.size()) {
				int x = range_gcd(i + 1, v[j], pref);
				if (a[i] - x >= o) {
					res = min(res, v[j] - i + 1);
					break;
				}

				while (k < u.size() and a[i] - o >= __gcd(x, range_gcd(u[k], i - 1, pref))) {
					k++;
				}
				if (k and a[i] - o >= __gcd(x, range_gcd(u[k - 1], i - 1, pref))) {
					res = min(res, v[j] - u[k - 1] + 1);
				}
			}
		}

		if (res == n + 1) {
			print(-1);
		}
		else {
			print(res);
		}
	}
}
