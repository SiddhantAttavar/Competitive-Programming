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

int32_t main() {
	setup();

	int n, m, k;
	input(n, m, k);

	vector<vector<int>> a(n, vector<int>(m));
	rep(i, 0, n) {
		arrput(a[i]);
	}
	a[0][0] ^= k;

	if (n == 1 and m == 1) {
		print(a[0][0] == 0);
		return 0;
	}

	if (n == 1 and m == 2) {
		print((a[0][0] ^ a[0][1]) == 0);
		return 0;
	}

	if (n == 2 and m == 1) {
		print((a[0][0] ^ a[1][0]) == 0);
		return 0;
	}

	vector<vector<vector<int>>> p(n, vector<vector<int>>(m));
	int t = n + m - 2;
	rep(i, 0, 1 << (t / 2)) {
		int x = 0, y = 0, s = a[0][0];
		rep(j, 0, t / 2) {
			if ((1 << j) & i) {
				x++;
			}
			else {
				y++;
			}
			if (x == n or y == m) {
				break;
			}
			s ^= a[x][y];
		}
		if (x < n and y < m) {
			s ^= a[x][y];
			p[x][y].push_back(s);
		}
	}
	rep(i, 0, n) {
		rep(j, 0, m) {
			sort(p[i][j].begin(), p[i][j].end());
		}
	}

	int res = 0;
	rep(i, 0, 1 << ((t + 1) / 2)) {
		int x = n - 1, y = m - 1, s = a[n - 1][m - 1];
		rep(j, 0, (t + 1) / 2) {
			if ((1 << j) & i) {
				x--;
			}
			else {
				y--;
			}
			if (x == -1 or y == -1) {
				break;
			}
			s ^= a[x][y];
		}
		if (x >= 0 and y >= 0) {
			res += upper_bound(p[x][y].begin(), p[x][y].end(), s) - lower_bound(p[x][y].begin(), p[x][y].end(), s);
		}
	}

	print(res);
}
