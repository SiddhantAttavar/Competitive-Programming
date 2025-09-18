#include <bits/stdc++.h>
#include <bits/extc++.h>
using namespace std;
using namespace __gnu_pbds; 
template<typename T> inline void input(T& x) {cin >> x;}
template<typename T, typename... S> inline void input(T& x, S&... args) {cin >> x; input(args ...);}
template<typename T> inline void print(T x) {cout << x << '\n';}
template<typename T, typename... S> inline void print(T x, S... args) {cout << x << ' '; print(args ...);}
#define debug(...) cout << #__VA_ARGS__ << ": "; print(__VA_ARGS__);
#define rep(i, a, b) for (auto i = (a); i < (b); i++)
#define arrput(l) for (auto &i : l) {cin >> i;}
#define arrprint(l) for (auto i : l) {cout << i << ' ';} cout << '\n'
#define setup() ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define int long long
#define ordered_set tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> 
const int MOD = (int) 1e9 + 7; //998244353;

bool check(vector<vector<int>> &a, vector<int> &c) {
	int n = c.size();
	if (a.size() != n) {
		return false;
	}
	rep(i, 0, n) {
		if (a[i].size() != n) {
			return false;
		}
	}
	rep(i, 0, n) {
		int j = n - 1;
		while (j >= 0 and a[j][i] == 0) {
			j--;
		}
		if (j == -1 or a[j][i] != c[i]) {
			return false;
		}

		j = n - 1;
		while (j >= 0 and a[i][j] == 0) {
			j--;
		}
		if (j == -1 or a[i][j] != c[n - i - 1]) {
			arrprint(c);
			cerr << i << ' ' << j << ' ' << c[n - i - 1] << endl;
			return false;
		}

		j = 0;
		while (j < n and a[i][j] == 0) {
			j++;
		}
		if (j == n or a[i][j] != c[i]) {
			return false;
		}

		j = 0;
		while (j < n and a[j][i] == 0) {
			j++;
		}
		if (j == n or a[j][i] != c[n - i - 1]) {
			return false;
		}
	}
	return true;
}

int32_t main() {
	setup();
	while (true) {
		int n;
		input(n);

		if (n == 0) {
			break;
		}

		vector<int> a(n);
		arrput(a);

		vector<vector<int>> res(n, vector<int>(n, 0));
		vector<int> s(n, false);
		bool flag = true;
		rep(l, 0, n / 2) {
			int r = n - l - 1;
			int u = r - (a[l] != a[r]), v = l;
			while (a[u] != a[l] and !s[u]) {
				u--;
			}
			while (a[v] != a[r] and !s[v]) {
				v++;
			}

			if (u < v) {
				flag = false;
				break;
			}

			if (u == v) {
				print(u, v, l, r);
				if (a[l] != a[r] and !s[l] and !s[r]) {
					flag = false;
					break;
				}
				int x = s[l] ? a[r] : a[l];
				res[u][l] = x;
				res[r][u] = x;
				res[n - u - 1][r] = x;
				res[l][n - u - 1] = x;
				s[u] = true;
				s[l] = true;
				s[r] = true;
				continue;
			}

			int x = a[v], y = a[u];
			a[v] = a[r];
			a[u] = a[l];
			rep(k, v, u + 1) {
				res[k][l] = a[k];
				res[r][k] = a[k];
				res[n - k - 1][r] = a[k];
				res[l][n - k - 1] = a[k];
				s[k] = true;
			}
			a[v] = x;
			a[u] = y;
			s[l] = true;
			s[r] = true;
		}

		if (n % 2 == 1) {
			res[n / 2][n / 2] = a[n / 2];
		}

		if (!flag) {
			print("No");
			cout.flush();
			continue;
		}

		print("Yes");
		rep(i, 0, n) {
			arrprint(res[i]);
		}
		cout.flush();
		assert(check(res, a));
	}
}
