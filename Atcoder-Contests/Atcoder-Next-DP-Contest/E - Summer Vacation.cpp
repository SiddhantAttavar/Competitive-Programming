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
#define endl '\n'
#define all(x) x.begin(), x.end()
#define sz(x) ((int) (x.size()))
#define ordered_set tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> 
typedef vector<int> vi; typedef pair<int, int> pii;
const int MOD = (int) 1e9 + 7; //998244353;

int32_t main() {
	setup();

	int n, m, q;
	input(n, m, q);

	int h = 20;
	vector<vi> p(n, vi(h, n + 1));
	rep(i, 0, m) {
		int a, b;
		input(a, b);
		p[a - 1][0] = min(p[a - 1][0], b);
	}
	for (int i = n - 2; i >= 0; i--) {
		p[i][0] = min(p[i][0], p[i + 1][0]);
		rep(j, 1, h) {
			if (p[i][j - 1] < n) {
				p[i][j] = p[p[i][j - 1]][j - 1];
			}
		}
	}

	while (q--) {
		int l, r;
		input(l, r);

		int u = l - 1, res = 0;
		for (int i = h - 1; i >= 0; i--) {
			if (u < n and p[u][i] <= r) {
				res += 1 << i;
				u = p[u][i];
			}
		}
		print(res);
	}
}
