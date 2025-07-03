#include <bits/stdc++.h>
#include <bits/extc++.h>
using namespace std;
using namespace __gnu_pbds; 
template<typename T> inline void input(T& x) {cin >> x;}
template<typename T, typename... S> inline void input(T& x, S&... args) {cin >> x; input(args ...);}
template<typename T> inline void print(T x) {cout << x << '\n';}
template<typename T, typename... S> inline void print(T x, S... args) {cout << x << ' '; print(args ...);}
template<typename T> inline void dbg(T x) {cerr << x << '\n';}
template<typename T, typename... S> inline void dbg(T x, S... args) {cerr << x << ", "; dbg(args ...);}
#define debug(...) cerr << #__VA_ARGS__ << ": "; dbg(__VA_ARGS__);
#define rep(i, a, b) for (auto i = (a); i < (b); i++)
#define arrput(l) for (auto &i : l) {cin >> i;}
#define arrprint(l) for (auto i : l) {cout << i << ' ';} cout << '\n'
#define setup() ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define int long long
#define ordered_set tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> 
const int MOD = (int) 1e9 + 7; //998244353;

void add_rows(int r, int c, int n, int m, vector<vector<int>> &v, vector<pair<int, int>> &res) {
	int a = n / 2 - r / 2, b = n / 2 + r / 2;
	int i = m / 2 - c / 2, j = m / 2 + c / 2;
	int x = n / 2, y = m / 2;
	res.push_back({a - 1, y});
	v[b][i]++;
	v[b][j]++;
	res.push_back({b + 1, y});
	v[a - 1][y]++;
	int p = y, q = y;
	while (p > i and q < j) {
		q++;
		res.push_back({b + 1, q});
		v[a - 1][p]++;
		res.push_back({a - 1, q});
		v[b + 1][p]++;
		p--;
		res.push_back({b + 1, p});
		v[a - 1][q]++;
		res.push_back({a - 1, p});
		v[b + 1][q]++;
	}
}

void add_cols(int r, int c, int n, int m, vector<vector<int>> &v, vector<pair<int, int>> &res) {
	int a = n / 2 - r / 2, b = n / 2 + r / 2;
	int i = m / 2 - c / 2, j = m / 2 + c / 2;
	int x = n / 2, y = m / 2;
	res.push_back({x, i - 1});
	v[a][j]++;
	v[b][j]++;
	res.push_back({x, j + 1});
	v[x][i - 1]++;
	int p = x, q = x;
	while (p > a and q < b) {
		q++;
		res.push_back({q, i - 1});
		v[p][j + 1]++;
		res.push_back({q, j + 1});
		v[p][i - 1]++;
		p--;
		res.push_back({p, i - 1});
		v[q][j + 1]++;
		res.push_back({p, j + 1});
		v[q][i - 1]++;
	}
}

int32_t main() {
	setup(); int tc; input(tc); while (tc--) {
		int n, m;
		input(n, m);

		vector<vector<int>> v(n, vector<int>(m, 0));
		vector<pair<int, int>> res = {{n / 2, m / 2}};
		int r = 1, c = 1;
		if (n >= 3 and m >= 3) {
			res = {
				{n / 2, m / 2},
				{n / 2, m / 2 - 1},
				{n / 2, m / 2 + 1},
				{n / 2 + 1, m / 2 - 1},
				{n / 2 - 1, m / 2},
				{n / 2 + 1, m / 2 + 1},
				{n / 2 + 1, m / 2},
				{n / 2 - 1, m / 2 + 1},
				{n / 2 - 1, m / 2 - 1}
			};
			v[n / 2 - 1][m / 2] = 1;
			v[n / 2][m / 2 - 1] = 2;
			v[n / 2][m / 2] = 1;
			v[n / 2][m / 2 + 1] = 1;
			v[n / 2 + 1][m / 2 - 1] = 2;
			v[n / 2 + 1][m / 2 + 1] = 1;
			r = 3;
			c = 3;
		}
		while (r < n and c < m) {
			add_rows(r, c, n, m, v, res);
			r += 2;
			add_cols(r, c, n, m, v, res);
			c += 2;
		}
		while (r < n) {
			add_rows(r, c, n, m, v, res);
			r += 2;
		}
		while (c < m) {
			add_cols(r, c, n, m, v, res);
			c += 2;
		}
		rep(i, 0, n) {
			rep(j, 0, m) {
				assert(v[i][j] <= 3);
			}
		}
		assert(res.size() == n * m);
		for (auto [x, y] : res) {
			assert(v[x][y] <= 3);
			v[x][y] = 4;
			print(x + 1, y + 1);
		}
	}
}
