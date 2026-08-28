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

const int N = (int) 1e4 + 1;
void solve(int l, int r, vector<array<int, 3>> &a, bitset<N> c, bitset<N> &z) {
	if (l == r) {
		for (auto [s, e, x] : a) {
			c |= c << x;
		}
		z |= c;
		return;
	}

	int m = (l + r) / 2;
	vector<array<int, 3>> f, g;
	for (auto [s, e, x] : a) {
		if (s <= l and r <= e) {
			c |= c << x;
			continue;
		}
		if (s <= m) {
			f.push_back({s, e, x});
		}
		if (e > m) {
			g.push_back({s, e, x});
		}
	}
	solve(l, m, f, c, z);
	solve(m + 1, r, g, c, z);
}

int32_t main() {
	setup();

	int n, q;
	input(n, q);

	vector<array<int, 3>> a;
	while (q--) {
		int l, r, x;
		input(l, r, x);
		a.push_back({l - 1, r - 1, x});
	}

	bitset<N> b = 1, res = 0;
	solve(0, n - 1, a, b, res);

	vi v;
	rep(i, 1, n + 1) {
		if (res[i]) {
			v.push_back(i);
		}
	}
	print(sz(v));
	arrprint(v);
}
