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

long double dist(long double a, long double b, long double x, long double y) {
	return sqrtl((a - x) * (a - x) + (b - y) * (b - y));
}

int32_t main() {
	setup();

	long double a, b, c;
	input(a, b, c);

	vector<pair<int, int>> v;
	if (a > b) {
		swap(a, b);
		v.push_back({0, 1});
	}
	if (b > c) {
		swap(b, c);
		v.push_back({1, 2});
	}
	if (a > b) {
		swap(a, b);
		v.push_back({0, 1});
	}

	long double t = (2 * c - a - b) / sqrt(3);
	long double y = (a - b) * (a - b) + t * t - (c - b) * (c - b);
	y = sqrtl(y);
	// long double p = dist(a, t, b, 0), q = dist(b, 0, c, y), r = dist(c, y, a, t);
	// assert(abs(p - q) < 1e-6 and abs(q - r) < 1e-6);

	long double u = 0;
	reverse(v.begin(), v.end());
	for (pair<int, int> p : v) {
		if (p.first == 0) {
			swap(t, u);
		}
		else {
			swap(u, y);
		}
	}

	cout << fixed << setprecision(30);
	print(t, u, y);
}
