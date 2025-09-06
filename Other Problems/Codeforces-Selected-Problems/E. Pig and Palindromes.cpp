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

int n, m;
vector<string> a;
vector<vector<pair<int, int>>> l;
vector<vector<int>> v;
vector<int> dp;
vector<int> ndp;
int z = 0;
int& get(int x, int y, int p, int q, vector<int> &a = dp) {
	if (x + y > p + q) {
		swap(x, y);
		swap(p, q);
	}
	if (x < 0 or y < 0 or p >= n or q >= m) {
		return z;
	}
	return a[(v[x][y]) * l[p + q].size() + v[p][q]];
}

int32_t main() {
	setup();

	input(n, m);

	a.resize(n);
	arrput(a);

	l.resize(n + m -1);
	v.assign(n, vector<int>(m));
	rep(i, 0, n) {
		rep(j, 0, m) {
			v[i][j] = l[i + j].size();
			l[i + j].push_back({i, j});
		}
	}

	dp = {a[0][0] == a[n - 1][m - 1]};
	int i = 1, j = n + m - 3;
	while (i < j) {
		vector<int> ndp(l[i].size() * l[j].size());
		for (auto [x, y] : l[i]) {
			for (auto [p, q] : l[j]) {
				if (a[x][y] != a[p][q]) {
					get(x, y, p, q, ndp) = 0;
					continue;
				}
				get(x, y, p, q, ndp) = (
					get(x - 1, y, p + 1, q) +
					get(x - 1, y, p, q + 1) +
					get(x, y - 1, p + 1, q) +
					get(x, y - 1, p, q + 1)
				) % MOD;
			}
		}
		dp = ndp;
		i++;
		j--;
	}

	int res = 0;
	if (i == j) {
		for (auto [x, y] : l[i]) {
			res = (
				res +
				get(x - 1, y, x + 1, y) +
				get(x - 1, y, x, y + 1) +
				get(x, y - 1, x + 1, y) +
				get(x, y - 1, x, y + 1)
			) % MOD;
		}
	}
	else {
		i--;
		j++;
		for (auto [x, y] : l[i]) {
			for (auto [p, q] : l[j]) {
				if (abs(x - p) + abs(y - q) <= 1) {
					res = (res + get(x, y, p, q)) % MOD;
				}
			}
		}
	}
	print(res);
}
