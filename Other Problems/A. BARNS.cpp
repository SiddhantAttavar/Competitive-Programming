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

int32_t main() {
	setup();

	int n;
	input(n);

	vector<vector<int>> v(n, vector<int>(3));
	vector<int> a, b;
	rep(i, 0, n) {
		arrput(v[i]);
		a.push_back(v[i][0]);
		b.push_back(v[i][1]);
	}
	a.erase(unique(a.begin(), a.end()), a.end());
	b.erase(unique(b.begin(), b.end()), b.end());
	sort(a.begin(), a.end());
	sort(b.begin(), b.end());

	map<int, int> x, y;
	int c = 0, d = 0;
	for (int i : a) {
		x[i] = c;
		c++;
	}
	for (int i : b) {
		y[i] = d;
		d++;
	}

	vector<vector<int>> p(c + 1, vector<int>(d + 1, 0));
	for (vector<int> i : v) {
		p[x[i[0]] + 1][y[i[1]] + 1] += i[2];
	}
	rep(i, 0, c) {
		rep(j, 0, d) {
			p[i + 1][j + 1] += p[i][j + 1] + p[i + 1][j] - p[i][j];
		}
	}
	int res = 0;
	vector<int> z(a.size() + b.size());
	merge(a.begin(), a.end(), b.begin(), b.end(), z.begin());
	z.erase(unique(z.begin(), z.end()), z.end());
	for (int e : z) {
		for (int f : z) {
			if (e > f) {
				continue;
			}
			int i = lower_bound(a.begin(), a.end(), e) - a.begin();
			int j = upper_bound(a.begin(), a.end(), f) - a.begin() - 1;
			int l = lower_bound(b.begin(), b.end(), e) - b.begin();
			int r = upper_bound(b.begin(), b.end(), f) - b.begin() - 1;
			if (l <= r and i <= j) {
				res = max(res, p[j + 1][r + 1] - p[j + 1][l] - p[i][r + 1] + p[i][l]);
			}
		}
	}
	print(res);
}
