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

const int N = 1e5;
map<int, int> a[4 * N];
pii b[4 * N];

void push(int l, int r, int c) {
	if (b[c].second != -1) {
		a[c] = {{b[c].second, r - l + 1}};
		if (l != r) {
			b[2 * c] = {0, b[c].second};
			b[2 * c + 1] = {0, b[c].second};
		}
		b[c].second = -1;
	}
	if (l != r) {
		b[2 * c].first += b[c].first;
		b[2 * c + 1].first += b[c].first;
	}
}

void upd2(int l, int r, int s, int e, int c, int x) {
	if (l > e or r < s) {
		return;
	}
	push(s, e, c);
	if (l <= s and e <= r) {
		b[c] = {0, x};
		int d = c;
		while (d) {
			for (auto [k, m] : a[c]) {
				a[d][k] -= m;
				if (a[d][k] == 0) {
					a[d].erase(k);
				}
			}
			d /= 2;
		}
		return;
	}
	int m = (s + e) / 2;
	upd2(l, r, s, m, 2 * c, x);
	upd2(l, r, m + 1, e, 2 * c + 1, x);
}

void upd3(int l, int r, int s, int e, int c, int x) {
	if (l > e or r < s) {
		return;
	}
	push(s, e, c);
	if (l <= s and e <= r) {
		b[c].first += x;
		return;
	}
	int m = (s + e) / 2;
	upd3(l, r, s, m, 2 * c, x);
	upd3(l, r, m + 1, e, 2 * c + 1, x);
}

int32_t main() {
	setup();

	int n, q;
	input(n, q);

	fill(b, b + 4 * N, pii(0, -1));

	vi t(n);
	arrput(t);
	rep(i, 0, n) {
		upd2(i, i, 0, n - 1, 1, t[i]);
	}

	while (q--) {
		int o;
		input(o);

		if (o == 1) {

		}
		else if (o == 2) {

		}
		else {

		}
	}
}
