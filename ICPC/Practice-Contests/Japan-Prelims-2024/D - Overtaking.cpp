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
			cout.flush();
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
		set<int> s;
		rep(i, 0, n) {
			s.insert(i);
		}
		bool flag = true;
		while (!s.empty()) {
			if (s.size() == 1) {
				int i = *s.begin();
				res[i][i] = a[i];
				res[n - i - 1][n - i - 1] = a[i];
				s.erase(s.begin());
				break;
			}

			int i = *s.begin();
			int j = *s.rbegin();
			s.erase(s.begin());
			s.erase(--s.end());

			int u = j, v = i;
			while (a[u] != a[i]) {
				u--;
			}
			while (a[v] != a[j]) {
				v++;
			}

			if (u < v) {
				flag = false;
				break;
			}

			rep(k, v, u + 1) {
				res[k][i] = a[k];
				res[j][k] = a[k];
				res[n - k - 1][j] = a[k];
				res[i][n - k - 1] = a[k];
				s.erase(k);
			}

			int p = max(n - u - 1, v), q = min(u, n - v - 1);
			if (p < q) {
				rep(k, i + 1, j) {
					res[q][k] = a[k];
					res[k][p] = a[k];
					res[p][k] = a[n - k - 1];
					res[k][q] = a[n - k - 1];
				}
				s.clear();
				break;
			}
		}

		if (!flag) {
			print("No");
			continue;
		}
		print("Yes");
		rep(i, 0, n) {
			arrprint(res[i]);
		}
		// assert(check(res, a));
	}
}
