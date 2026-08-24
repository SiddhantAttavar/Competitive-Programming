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

const int N = 3e5;
vector<pii> a[N], b[N];

vector<pii> comb(vector<pii> x, vector<pii> y) {
	for (int i = sz(x) - 1; i > 0; i--) {
		x[i].second -= x[i - 1].second;
	}
	for (int i = sz(y) - 1; i > 0; i--) {
		y[i].second -= y[i - 1].second;
	}
	vector<pii> z(sz(x) + sz(y));
	merge(all(x), all(y), z.begin());
	rep(i, 1, sz(z)) {
		z[i].second += z[i - 1].second;
	}
	return z;
}

void build(int l, int r, int c, vector<array<int, 6>> &v) {
	if (l == r) {
		a[c] = {{-1, v[l][2]}, {v[l][0] + 1, v[l][4]}, {v[l][1] + 1, v[l][5]}};
		b[c] = {{-1, 0}, {v[l][0] + 1, v[l][3]}, {v[l][1] + 1, 0}};
		return;
	}
	int m = (l + r) / 2;
	build(l, m, 2 * c, v);
	build(m + 1, r, 2 * c + 1, v);
	a[c] = comb(a[2 * c], a[2 * c + 1]);
	b[c] = comb(b[2 * c], b[2 * c + 1]);
}

pii query(int l, int r, int s, int e, int c, int x) {
	if (l > e or r < s) {
		return {0, 0};
	}

	if (l <= s and e <= r) {
		return {
			prev(upper_bound(all(a[c]), pii(x, 1e18)))->second,
			prev(upper_bound(all(b[c]), pii(x, 1e18)))->second
		};
	}

	int m = (s + e) / 2;
	auto [p, q] = query(l, r, s, m, 2 * c, x);
	auto [u, v] = query(l, r, m + 1, e, 2 * c + 1, x);
	return {p + u, q + v};
}

int32_t main() {
	setup();

	int n;
	input(n);

	vector<array<int, 6>> v(n);
	rep(i, 0, n) {
		arrput(v[i]);
	}
	build(0, n - 1, 1, v);

	int m;
	input(m);
	int k = 0;
	while (m--) {
		int l, r, x;
		input(l, r, x);

		l--;
		r--;
		x = (x + k) % ((int) 1e9);

		auto [p, q] = query(l, r, 0, n - 1, 1, x);
		k = p + q * x;
		print(k);
	}
}
