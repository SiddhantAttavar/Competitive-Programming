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

int32_t main() {
	setup();

	int n, q;
	input(n, q);

	vector<string> a(n);
	arrput(a);

	vector<vector<int>> p(n, vector<int>(n, 0));
	rep(i, 0, n - 1) {
		rep(j, 0, n - 1) {
			p[i + 1][j + 1] = p[i][j + 1] + p[i + 1][j] - p[i][j] + (a[i][j] == '.' and a[i + 1][j] == '.' and a[i][j + 1] == '.' and a[i + 1][j + 1] == '.');
		}
	}

	while (q--) {
		int a, b, c, d;
		input(a, b, c, d);

		a--;
		b--;
		c--;
		d--;
		print(p[b][d] - p[b][c] - p[a][d] + p[a][c]);
	}
}
