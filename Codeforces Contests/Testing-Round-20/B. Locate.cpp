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

bool debug = false;
int n;
vector<int> p;

int query(int l, int r) {
	// assert(l >= 0 and l <= r and r < n);
	if (debug) {
		return *max_element(p.begin() + l, p.begin() + r + 1) - *min_element(p.begin() + l, p.begin() + r + 1);
	}
	print('?', l + 1, r + 1);
	cout.flush();
	int x;
	input(x);
	return x;
}

pair<int, bool> encode() {
	input(n);

	p.clear();
	p.resize(n);
	arrput(p);

	for (int i : p) {
		if (i == 1) {
			return {n, false};
		}
		else if (i == n) {
			return {n, true};
		}
	}
	return {n, true};
}

void decode(pair<int, bool> p) {
	auto [n, b] = p;
	int l = 0, r = n - 2, v = n - 1;
	while (l <= r) {
		int m = (l + r) / 2;
		if (query(0, m) == n - 1) {
			v = m;
			r = m - 1;
		}
		else {
			l = m + 1;
		}
	}
	l = 1, r = n - 1;
	int u = 0;
	while (l <= r) {
		int m = (l + r) / 2;
		if (query(m, n - 1) == n - 1) {
			u = m;
			l = m + 1;
		}
		else {
			r = m - 1;
		}
	}
	print('!', (b ? u : v) + 1);
	cout.flush();
}

int32_t main() {
	setup();

	string s;
	input(s);

	int tc;
	input(tc);
	while (tc--) {
		if (s == "first") {
			auto [n, b] = encode();
			print(b);
		}
		else if (s == "second") {
			int n, x;
			input(n, x);
			decode({n, x});
		}
		else {
			decode(encode());
		}
	}
}
